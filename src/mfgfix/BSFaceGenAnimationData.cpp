#include "BSFaceGenAnimationData.h"
//#include "REL/SafeWrite.h"
#include "Offsets.h"
//#include "GameSettings.h"
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

	bool BSFaceGenAnimationData::KeyframesUpdate_Hook(float a_timeDelta, bool a_updateBlinking)
	{
		RE::BSSpinLockGuard locker(lock);

		unk217 = false;

		// @removed
		//if (updateBlinking)
		//	UpdateEyesBlinking(timeDelta);
		/*
		if (unk21A)	{
			// @removed
			//float blinkLeft = modifier3.count > 0 ? modifier3.values[0] : 0.0f;
			//float blinkRight = modifier3.count > 1 ? modifier3.values[1] : 0.0f;

			// @removed
			//if ((blinkLeft < 1.0f || blinkRight < 1.0f) && eyesBlinkingStage != BlinkingStage::BlinkDownAndWait1)
			// @added
			if (eyesBlinkingStage != BlinkingStage::BlinkDownAndWait1) {
				// @removed

				//BSSpinLockGuard locker(lock);

				//if (!expressionOverride && transitionTarget)
				//{
				//	// Todo:
				//	// UnkFunc_66E0(&transitionTarget, keyFrameCache_1790);
				//}

				//expression1.timer = 0.0f;
				//if (!expression1.isUpdated)
				//	expression1.Reset(true);
				//modifier1.timer = 0.0f;
				//modifier1.Reset(true);
				//phoneme1.timer = 0.0f;
				//phoneme1.Reset(true);
				//
				//if (unk228)
				//{
				//	// Todo:
				//	// UnkFunc_49F0(UnkObject_4840.unk_D0, unk228);
				//	// unk228 = nullptr;
				//}

				//expression2.timer = 0.0f;
				//expression2.Reset(true);
				//modifier2.timer = 0.0f;
				//modifier2.Reset(true);
				//phoneme2.timer = 0.0f;
				//phoneme2.Reset(true);

				//expression3.Reset(true);
				//modifier3.Reset(true);
				//phoneme3.Reset(true);

				// @added
				Reset(0.0f, true, true, true, false);

				// @removed
				//modifier3.SetValue(0, 1.0f);
				//modifier3.SetValue(1, 1.0f);

				unk217 = true;

				eyesBlinkingStage = BlinkingStage::BlinkDownAndWait1;
				eyesBlinkingTimer = 0.0f;
			}
		}
		*/
		// @removed
		//if (timeDelta > 0.0f)
		{
			//bool flag1, flag2, flag3, flag4, flag5;

			// @removed

			//flag1 = expression1.TransitionUpdate(timeDelta, transitionTarget);
			//flag2 = (!unk21C && unk21B) || expression2.Unk0B(); // has value > 0

			//if (!flag1 && !flag2)
			//{
			//	if (!expressionOverride && transitionTarget)
			//	{
			//		// Todo:
			//		// UnkFunc_66E0(&transitionTarget, keyFrameCache_1790);
			//	}
			//}

			//if (flag1)
			//{
			//	expression3.Copy(&expression1);

			//	if (flag2)
			//		expression3.Interpolate2(&expression2, 1.0f, false, false);
			//}
			//else
			//{
			//	if (flag2)
			//		expression3.Copy(&expression2);
			//}

			//flag3 = flag1 || flag2;

			// @added

			// expressions
			{
				auto merge = [](BSFaceGenKeyframeMultiple& a_src, BSFaceGenKeyframeMultiple& a_dst) {
					if (!a_src.IsZero()) {
						a_dst.Copy(&a_src);
					}
				};

				expression3.Reset();

				expression1.TransitionUpdate(a_timeDelta, transitionTarget);

				merge(expression1, expression3);
				merge(expression2, expression3);

				//std::vector<float> merged(expression3.count, 0.0f);

				//std::copy(expression1.values, expression1.values + std::min((std::size_t)expression1.count, std::size(merged)), std::begin(merged));
				//MergeValues<BSFaceGenKeyframe::Type::Expression>(expression2.values, expression2.values + std::min((std::size_t)expression2.count, std::size(merged)), std::begin(merged));

				//if (!std::equal(std::begin(merged), std::end(merged), expression3.values, AlmostEqual))
				//{
				//	std::copy(std::begin(merged), std::end(merged), expression3.values);
				//	expression3.isUpdated = false;
				//	unk217 = true;
				//}
			}

			// @removed

			//flag1 = UpdateDialogModifiers(timeDelta);
			//flag2 = (!unk21C && unk21B) || modifier2.Unk0B(); // has value > 0

			//if (flag1)
			//{
			//	modifier3.Copy(&modifier1);

			//	if (flag2)
			//		modifier3.Interpolate2(&modifier2, 1.0f, false, false);
			//}
			//else
			//{
			//	if (flag2)
			//		modifier3.Copy(&modifier2);
			//}

			//flag1 = flag1 || flag2;

			// @added

			// modifiers
			{
				auto merge = [](BSFaceGenKeyframeMultiple& a_src, BSFaceGenKeyframeMultiple& a_dst) {
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

				//DialogModifiersUpdate(timeDelta);

				//std::vector<float> eyesBlinking(modifier3.count, 0.0f);
				//std::vector<float> eyesMovement(modifier3.count, 0.0f);

				//EyesBlinkingUpdate(timeDelta, eyesBlinking);
				//EyesDirectionUpdate(timeDelta, eyesMovement);

				//std::vector<float> merged(modifier3.count, 0.0f);

				//std::copy(std::begin(eyesBlinking), std::begin(eyesBlinking) + std::min(std::size(eyesBlinking), std::size(merged)), std::begin(merged));
				//MergeValues<BSFaceGenKeyframe::Type::Modifier>(modifier1.values, modifier1.values + std::min((std::size_t)modifier1.count, std::size(merged)), std::begin(merged));
				//MergeValues<BSFaceGenKeyframe::Type::Modifier>(std::begin(eyesMovement), std::begin(eyesMovement) + std::min(std::size(eyesMovement), std::size(merged)), std::begin(merged));
				//MergeValues<BSFaceGenKeyframe::Type::Modifier>(modifier2.values, modifier2.values + std::min((std::size_t)modifier2.count, std::size(merged)), std::begin(merged));

				//if (!std::equal(std::begin(merged), std::end(merged), modifier3.values, AlmostEqual))
				//{
				//	std::copy(std::begin(merged), std::end(merged), modifier3.values);
				//	modifier3.isUpdated = false;
				//	unk217 = true;
				//}
			}

			// @removed

			//flag2 = UpdateDialogPhonemes(timeDelta);
			//flag4 = (!unk21C && unk21B) || phoneme2.Unk0B(); // has value > 0

			//if (flag2)
			//{
			//	phoneme3.Copy(&phoneme1);

			//	if (flag4)
			//		phoneme3.Interpolate2(&phoneme2, 1.0f, false, false);
			//}
			//else
			//{
			//	if (flag4)
			//		phoneme3.Copy(&phoneme2);
			//}

			//flag2 = flag2 || flag4;

			// @added

			// phonemes
			{
				auto merge = [](BSFaceGenKeyframeMultiple& a_src, BSFaceGenKeyframeMultiple& a_dst) {
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

				//DialoguePhonemesUpdate(timeDelta);

				//std::vector<float> merged(phoneme3.count, 0.0f);

				//std::copy(phoneme1.values, phoneme1.values + std::min((std::size_t)phoneme1.count, std::size(merged)), std::begin(merged));
				//MergeValues<BSFaceGenKeyframe::Type::Phoneme>(phoneme2.values, phoneme2.values + std::min((std::size_t)phoneme2.count, std::size(merged)), std::begin(merged));

				//if (!std::equal(std::begin(merged), std::end(merged), phoneme3.values, AlmostEqual))
				//{
				//	std::copy(std::begin(merged), std::end(merged), phoneme3.values);
				//	phoneme3.isUpdated = false;
				//	unk217 = true;
				//}
			}

			// @removed

			//flag5 = (!unk21C && unk21B) || custom2.Unk0B(); // has value > 0

			//if (flag5)
			//	custom3.Copy(&custom2);

			// @added

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

				merge(custom2, custom3);
				//if (!std::equal(custom2.values, custom2.values + std::min(custom2.count, custom3.count), custom3.values, AlmostEqual)) {
				//	std::copy(custom2.values, custom2.values + std::min(custom2.count, custom3.count), custom3.values);
				//	custom3.isUpdated = false;
				//	unk217 = true;
				//}
			}

			// @removed
			//unk217 |= flag1 || flag2 || flag3 || flag5;

			{
				// Issue: flickering facial expressions.
				// Sometimes update is needed even if keyframes values were not changed.
				// For example, SKSE calls UpdateModelFace() in functions SetExpressionPhoneme() and SetExpressionModifier() that cause reseting of all face morphs.
				//unk217 |= expressionOverride || expression2.Unk_0B() || modifier2.Unk_0B() || phoneme2.Unk_0B() || custom2.Unk_0B();
				unk217 = true;
			}

			CheckAndReleaseDialogueData();
		}

		// @removed
		//unk21C = unk21B;

		return unk217;
	}

	void BSFaceGenAnimationDataNS::Init()
	{
		auto KeyframesUpdateAddr = Offsets::BSFaceGenAnimationData::KeyframesUpdate.address();
		auto KeyframesUpdateHook = &BSFaceGenAnimationData::KeyframesUpdate_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&KeyframesUpdateAddr), reinterpret_cast<PVOID&>(KeyframesUpdateHook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}

		// Remove eyes direction update from UpdateDownwardPass because it is now in KeyframesUpdate.
		REL::safe_write(Offsets::BSFaceGenNiNode::sub_3F1800.address() + 0x0139, static_cast<std::uint16_t>(0x47EB));
	}
}