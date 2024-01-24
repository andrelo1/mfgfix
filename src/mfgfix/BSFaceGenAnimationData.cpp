#include "BSFaceGenAnimationData.h"
#include "Offsets.h"
#include "Settings.h"

namespace MfgFix
{
	namespace
	{
		constexpr float pi_180 = 0.0174532925f;

		float rand(float a_min, float a_max)
		{
			return a_min + (a_max - a_min) * (static_cast<float>(std::rand()) / RAND_MAX);
		}

		float rand(float a_min, float a_max, float a_exp)
		{
			return a_min + (a_max - a_min) * pow(static_cast<float>(std::rand()) / RAND_MAX, a_exp);
		}

		float deg2rad(float a_degrees)
		{
			return a_degrees * pi_180;
		}
	}

	void BSFaceGenAnimationData::SetExpressionOverride(std::uint32_t a_idx, float a_value)
	{
		using func_t = decltype(&BSFaceGenAnimationData::SetExpressionOverride);
		REL::Relocation<func_t> func(Offsets::BSFaceGenAnimationData::SetExpressionOverride);
		func(this, a_idx, a_value);
	}

	void BSFaceGenAnimationData::ClearExpressionOverride()
	{
		expressionOverride = false;
	}

	void BSFaceGenAnimationData::Reset(float a_timer, bool a_resetExpression, bool a_resetModifierAndPhoneme, bool a_resetCustom, bool a_closeEyes)
	{
		using func_t = decltype(&BSFaceGenAnimationData::Reset);
		REL::Relocation<func_t> func(Offsets::BSFaceGenAnimationData::Reset);
		func(this, a_timer, a_resetExpression, a_resetModifierAndPhoneme, a_resetCustom, a_closeEyes);
	}
	
	std::uint32_t BSFaceGenAnimationData::GetActiveExpression() const
	{
		std::uint32_t expression = Expression::MoodNeutral;

		for (std::uint32_t i = 0; i < expression3.count; ++i) {
			if (expression3.values[i] > expression3.values[expression]) {
				expression = i;
			}
		}

		return expression;
	}

	void BSFaceGenAnimationData::DialogueModifiersUpdate(float a_timeDelta)
	{
		if (!dialogueData || (((dialogueData->refCount & 0x70000000) + 0xD0000000) & 0xEFFFFFFF) != 0) {
			return;
		}

		REL::Relocation<bool(void*, float, float*)> sub_1FCD10{ REL::ID(16267) };

		modifier1.timer += a_timeDelta;
		sub_1FCD10(dialogueData->unk28, modifier1.timer, modifier1.values);
	}

	void BSFaceGenAnimationData::DialoguePhonemesUpdate(float a_timeDelta)
	{
		if (!dialogueData || (((dialogueData->refCount & 0x70000000) + 0xD0000000) & 0xEFFFFFFF) != 0) {
			return;
		}

		REL::Relocation<bool(void*, float, float*)> sub_1FC9B0{ REL::ID(16266) };

		phoneme1.timer += a_timeDelta;
		sub_1FC9B0(dialogueData->unk28, phoneme1.timer, phoneme1.values);
	}
	
	void BSFaceGenAnimationData::CheckAndReleaseDialogueData()
	{
		if (!dialogueData || (((dialogueData->refCount & 0x70000000) + 0xD0000000) & 0xEFFFFFFF) != 0) {
			return;
		}

		auto timer = (dialogueData->unk28->unk0 + (dialogueData->unk28->unk4 < 0 ? -dialogueData->unk28->unk4 : 0)) * 0.033f + 0.2f;

		if (phoneme1.timer <= timer) {
			return;
		}

		REL::Relocation<void(void*)> ReleaseDialogueData{ REL::ID(16318) };

		ReleaseDialogueData(dialogueData);

		dialogueData = nullptr;
	}

	void BSFaceGenAnimationData::EyesBlinkingUpdate(float a_timeDelta)
	{
		auto& settings = Settings::Get();

		eyesBlinkingTimer = std::max(eyesBlinkingTimer - a_timeDelta, 0.0f);
		auto blinkValue = 0.0f;

		switch (eyesBlinkingStage) {
			case EyesBlinkingStage::BlinkDelay:	{
				blinkValue = 0.0f;

				if (eyesBlinkingTimer == 0.0f) {
					eyesBlinkingStage = EyesBlinkingStage::BlinkDown;
					eyesBlinkingTimer = settings.eyesBlinking.fBlinkDownTime;
				}

				break;
			}
			case EyesBlinkingStage::BlinkDown: {
				blinkValue = settings.eyesBlinking.fBlinkDownTime != 0.0f ? 1.0f - eyesBlinkingTimer / settings.eyesBlinking.fBlinkDownTime : 1.0f;

				if (eyesBlinkingTimer == 0.0f) {
					eyesBlinkingStage = EyesBlinkingStage::BlinkUp;
					eyesBlinkingTimer = settings.eyesBlinking.fBlinkUpTime;
				}

				break;
			}
			case EyesBlinkingStage::BlinkUp: {
				blinkValue = settings.eyesBlinking.fBlinkUpTime != 0.0f ? eyesBlinkingTimer / settings.eyesBlinking.fBlinkUpTime : 0.0f;

				if (eyesBlinkingTimer == 0.0f) {
					eyesBlinkingStage = EyesBlinkingStage::BlinkDelay;
					eyesBlinkingTimer = rand(settings.eyesBlinking.fBlinkDelayMin, settings.eyesBlinking.fBlinkDelayMax, 2.0f);
				}

				break;
			}
			case EyesBlinkingStage::BlinkDownAndWait1: {
				if (unk21A)	{
					blinkValue = settings.eyesBlinking.fBlinkDownTime != 0.0f ? 1.0f - eyesBlinkingTimer / settings.eyesBlinking.fBlinkDownTime : 1.0f;
				} else {
					blinkValue = 1.0f;
					eyesBlinkingStage = EyesBlinkingStage::BlinkUp;
					eyesBlinkingTimer = settings.eyesBlinking.fBlinkUpTime;
				}

				break;
			}
			case EyesBlinkingStage::BlinkDownAndWait2: {
				eyesBlinkingStage = EyesBlinkingStage::BlinkDownAndWait1;

				break;
			}
			default: {
				blinkValue = 0.0f;
				eyesBlinkingStage = EyesBlinkingStage::BlinkDelay;
				eyesBlinkingTimer = rand(settings.eyesBlinking.fBlinkDelayMin, settings.eyesBlinking.fBlinkDelayMax, 2.0f);

				break;
			}
		}

		blinkValue = std::clamp(blinkValue, 0.0f, 1.0f);

		modifier3.values[Modifier::BlinkLeft] = blinkValue;
		modifier3.values[Modifier::BlinkRight] = blinkValue;
	}

	void BSFaceGenAnimationData::EyesMovementUpdate(float a_timeDelta)
	{
		auto& settings = Settings::Get();

		eyesOffsetTimer = std::max(eyesOffsetTimer - a_timeDelta, 0.0f);

		if (eyesOffsetTimer > 0.0f) {
			return;
		}

		switch (GetActiveExpression()) {
			case Expression::DialogueAnger:
			case Expression::MoodAnger:	{
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionAngry, settings.eyesMovement.fEyeOffsetDelayMaxEmotionAngry, 2.0f);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionAngry, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionAngry);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionAngry, settings.eyesMovement.fEyePitchMaxOffsetEmotionAngry);

				break;
			}
			case Expression::DialogueHappy:
			case Expression::MoodHappy:	{
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionHappy, settings.eyesMovement.fEyeOffsetDelayMaxEmotionHappy, 0.5f);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionHappy, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionHappy);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionHappy, settings.eyesMovement.fEyePitchMaxOffsetEmotionHappy);

				break;
			}
			case Expression::DialogueSurprise:
			case Expression::MoodSurprise: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionSurprise, settings.eyesMovement.fEyeOffsetDelayMaxEmotionSurprise, 0.5f);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionSurprise, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionSurprise);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionSurprise, settings.eyesMovement.fEyePitchMaxOffsetEmotionSurprise);

				break;
			}
			case Expression::DialogueSad:
			case Expression::MoodSad: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionSad, settings.eyesMovement.fEyeOffsetDelayMaxEmotionSad);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionSad, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionSad);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionSad, settings.eyesMovement.fEyePitchMaxOffsetEmotionSad);

				break;
			}
			case Expression::DialogueFear:
			case Expression::MoodFear: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionFear, settings.eyesMovement.fEyeOffsetDelayMaxEmotionFear);
				eyesHeadingOffset = rand(0.0f, 1.0f) <= 0.5f ? 0.0f : rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionFear, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionFear);
				eyesPitchOffset = rand(0.0f, 1.0f) <= 0.5f ? 0.0f : rand(settings.eyesMovement.fEyePitchMinOffsetEmotionFear, settings.eyesMovement.fEyePitchMaxOffsetEmotionFear);

				break;
			}
			case Expression::DialoguePuzzled:
			case Expression::MoodPuzzled: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionPuzzled, settings.eyesMovement.fEyeOffsetDelayMaxEmotionPuzzled);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionPuzzled, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionPuzzled);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionPuzzled, settings.eyesMovement.fEyePitchMaxOffsetEmotionPuzzled);

				break;
			}
			case Expression::DialogueDisgusted:
			case Expression::MoodDisgusted:	{
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionDisgusted, settings.eyesMovement.fEyeOffsetDelayMaxEmotionDisgusted);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionDisgusted, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionDisgusted);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionDisgusted, settings.eyesMovement.fEyePitchMaxOffsetEmotionDisgusted);

				break;
			}
			case Expression::CombatAnger: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionCombatAnger, settings.eyesMovement.fEyeOffsetDelayMaxEmotionCombatAnger);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionCombatAnger, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionCombatAnger);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionCombatAnger, settings.eyesMovement.fEyePitchMaxOffsetEmotionCombatAnger);

				break;
			}
			case Expression::CombatShout: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionCombatShout, settings.eyesMovement.fEyeOffsetDelayMaxEmotionCombatShout);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionCombatShout, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionCombatShout);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionCombatShout, settings.eyesMovement.fEyePitchMaxOffsetEmotionCombatShout);

				break;
			}
			default: {
				eyesOffsetTimer = rand(settings.eyesMovement.fEyeOffsetDelayMinEmotionNeutral, settings.eyesMovement.fEyeOffsetDelayMaxEmotionNeutral, 2.0f);
				eyesHeadingOffset = rand(settings.eyesMovement.fEyeHeadingMinOffsetEmotionNeutral, settings.eyesMovement.fEyeHeadingMaxOffsetEmotionNeutral);
				eyesPitchOffset = rand(settings.eyesMovement.fEyePitchMinOffsetEmotionNeutral, settings.eyesMovement.fEyePitchMaxOffsetEmotionNeutral);

				break;
			}
		}
	}

	void BSFaceGenAnimationData::EyesDirectionUpdate(float a_timeDelta)
	{
		auto& settings = Settings::Get();

		auto eyesHeadingMax = deg2rad(settings.eyesMovement.fTrackEyeXY);
		auto eyesPitchMax = deg2rad(settings.eyesMovement.fTrackEyeZ);
		auto eyesHeadingDeltaMax = settings.eyesMovement.fTrackSpeed * a_timeDelta;
		auto eyesPitchDeltaMax = settings.eyesMovement.fTrackSpeed * a_timeDelta;

		eyesHeading = std::clamp(eyesHeadingBase + eyesHeadingOffset, eyesHeading - eyesHeadingDeltaMax, eyesHeading + eyesHeadingDeltaMax);
		eyesPitch = std::clamp(eyesPitchBase + eyesPitchOffset, eyesPitch - eyesPitchDeltaMax, eyesPitch + eyesPitchDeltaMax);
		eyesHeading = std::clamp(eyesHeading, -eyesHeadingMax, eyesHeadingMax);
		eyesPitch = std::clamp(eyesPitch, -eyesPitchMax, eyesPitchMax);

		modifier3.values[Modifier::LookLeft] = eyesHeading < 0.0f ? (eyesHeadingMax != 0.0f ? -eyesHeading / eyesHeadingMax : 0.0f) : 0.0f;
		modifier3.values[Modifier::LookRight] = eyesHeading > 0.0f ? (eyesHeadingMax != 0.0f ? eyesHeading / eyesHeadingMax : 0.0f) : 0.0f;
		modifier3.values[Modifier::LookDown] = eyesPitch < 0.0f ? (eyesPitchMax != 0.0f ? -eyesPitch / eyesPitchMax : 0.0f) : 0.0f;
		modifier3.values[Modifier::LookUp] = eyesPitch > 0.0f ? (eyesPitchMax != 0.0f ? eyesPitch / eyesPitchMax : 0.0f) : 0.0f;
	}

	bool BSFaceGenAnimationData::KeyframesUpdateHook(float a_timeDelta, bool /* a_updateBlinking */)
	{
		RE::BSSpinLockGuard locker(lock);

		// expressions
		{
			auto merge = [](Keyframe& a_src, Keyframe& a_dst) {
				if (!a_src.IsZero()) {
					a_dst.Copy(&a_src);
				}
			};

			expression3.Reset();

			expression1.TransitionUpdate(a_timeDelta, transitionTarget);

			merge(expression1, expression3);
			merge(expression2, expression3);
		}

		// modifiers
		{
			auto merge = [](Keyframe& a_src, Keyframe& a_dst) {
				auto count = std::min(a_src.count, a_dst.count);
				for (std::uint32_t i = 0; i < count; ++i) {
					if (a_src.values[i] != 0.0f) {
						a_dst.values[i] = a_src.values[i];
					}
				}
				if (a_src.values[Modifier::LookDown] != 0.0f || a_src.values[Modifier::LookLeft] != 0.0f || a_src.values[Modifier::LookRight] != 0.0f || a_src.values[Modifier::LookUp] != 0.0f) {
					a_dst.values[Modifier::LookDown] = a_src.values[Modifier::LookDown];
					a_dst.values[Modifier::LookLeft] = a_src.values[Modifier::LookLeft];
					a_dst.values[Modifier::LookRight] = a_src.values[Modifier::LookRight];
					a_dst.values[Modifier::LookUp] = a_src.values[Modifier::LookUp];
				}
			};

			modifier3.Reset();

			DialogueModifiersUpdate(a_timeDelta);
			EyesBlinkingUpdate(a_timeDelta);

			merge(modifier1, modifier3);

			if (!unk21A) {
				EyesMovementUpdate(a_timeDelta);
				EyesDirectionUpdate(a_timeDelta);
			}

			merge(modifier2, modifier3);
		}

		// phonemes
		{
			auto merge = [](Keyframe& a_src, Keyframe& a_dst) {
				auto count = std::min(a_src.count, a_dst.count);
				for (std::uint32_t i = 0; i < count; ++i) {
					if (a_src.values[i] != 0.0f) {
						a_dst.values[i] = a_src.values[i];
					}
				}
			};

			phoneme3.Reset();

			DialoguePhonemesUpdate(a_timeDelta);

			merge(phoneme1, phoneme3);
			merge(phoneme2, phoneme3);
		}

		// custom
		{
			auto merge = [](BSFaceGenKeyframeMultiple& a_src, BSFaceGenKeyframeMultiple& a_dst) {
				auto count = std::min(a_src.count, a_dst.count);
				for (std::uint32_t i = 0; i < count; ++i) {
					if (a_src.values[i] != 0.0f) {
						a_dst.values[i] = a_src.values[i];
					}
				}
			};

			custom3.Reset();

			merge(custom1, custom3);
			merge(custom2, custom3);
		}

		CheckAndReleaseDialogueData();

		unk217 = true;

		return unk217;
	}

	void BSFaceGenAnimationData::Init()
	{
		auto KeyframesUpdateAddr = Offsets::BSFaceGenAnimationData::KeyframesUpdate.address();
		auto KeyframesUpdateHookAddr = &KeyframesUpdateHook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&KeyframesUpdateAddr), reinterpret_cast<PVOID&>(KeyframesUpdateHookAddr));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}

		// remove eyes update from UpdateDownwardPass, it was moved to KeyframesUpdate
		REL::safe_write(Offsets::BSFaceGenNiNode::sub_3F1800.address() + 0x0139, static_cast<std::uint16_t>(0x47EB));
	}
}
