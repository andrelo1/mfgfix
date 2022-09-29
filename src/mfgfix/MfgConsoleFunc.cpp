#include "MfgConsoleFunc.h"
#include "BSFaceGenAnimationData.h"

namespace MfgFix::MfgConsoleFunc
{
	namespace
	{
		enum Mode : std::int32_t
		{
			Reset = -1,
			Phoneme,
			Modifier,
			ExpressionValue,
			ExpressionId
		};
	}

	std::uint32_t GetActiveExpression(const BSFaceGenAnimationData& a_animData)
	{
		std::uint32_t expression = BSFaceGenAnimationData::Expression::MoodNeutral;

		for (std::uint32_t i = 0; i < a_animData.expression1.count; ++i) {
			if (a_animData.expression1.values[i] > a_animData.expression1.values[expression]) {
				expression = i;
			}
		}

		return expression;
	}

	bool SetPhonemeModifier(RE::StaticFunctionTag*, RE::Actor* a_actor, std::int32_t a_mode, std::uint32_t a_id, std::int32_t a_value)
	{
		if (!a_actor) {
			return false;
		}

		auto animData = reinterpret_cast<BSFaceGenAnimationData*>(a_actor->GetFaceGenAnimationData());

		if (!animData) {
			return false;
		}

		RE::BSSpinLockGuard locker(animData->lock);

		switch (a_mode) {
			case Mode::Reset: {
				animData->ClearExpressionOverride();
				animData->Reset(0.0f, true, true, true, false);
				return true;
			}
			case Mode::Phoneme:	{
				animData->phoneme2.SetValue(a_id, std::clamp(a_value, 0, 100) / 100.0f);
				return true;
			}
			case Mode::Modifier: {
				animData->modifier2.SetValue(a_id, std::clamp(a_value, 0, 100) / 100.0f);
				return true;
			}
		}

		return false;
	}

	std::int32_t GetPhonemeModifier(RE::StaticFunctionTag*, RE::Actor* a_actor, std::int32_t a_mode, std::uint32_t a_id)
	{
		if (!a_actor) {
			return -1;
		}

		auto animData = reinterpret_cast<BSFaceGenAnimationData*>(a_actor->GetFaceGenAnimationData());

		if (!animData) {
			return -1;
		}

		RE::BSSpinLockGuard locker(animData->lock);

		switch(a_mode) {
			case Mode::Phoneme:	{
				return a_id < animData->phoneme2.count ? std::lround(animData->phoneme2.values[a_id] * 100.0f) : 0;
			}
			case Mode::Modifier: {
				return a_id < animData->modifier2.count ? std::lround(animData->modifier2.values[a_id] * 100.0f) : 0;
			}
			case Mode::ExpressionValue: {
				return a_id < animData->expression1.count ? std::lround(animData->expression1.values[a_id] * 100.0f) : 0;
			}
			case Mode::ExpressionId: {
				return GetActiveExpression(*animData);
			}
		}

		return -1;
	}

	void Register()
	{
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("SetPhonemeModifier", "MfgConsoleFunc", SetPhonemeModifier);
			a_vm->RegisterFunction("GetPhonemeModifier", "MfgConsoleFunc", GetPhonemeModifier);

			return true;
		});
	}
}