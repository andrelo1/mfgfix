#include "ConsoleCommands.h"
#include "BSFaceGenAnimationData.h"
#include "Offsets.h"

namespace MfgFix::ConsoleCommands
{
	using Keyframe = BSFaceGenAnimationData::Keyframe;

	namespace
	{
		uintptr_t ModifyFaceGen_ExecuteAddr{ 0 };
	}

	void SetValue(RE::TESObjectREFR* a_ref, Keyframe::Type a_keyframeType, std::uint32_t a_idx, float a_value)
	{
		if (!a_ref) {
			return;
		}

		auto animData = reinterpret_cast<BSFaceGenAnimationData*>(a_ref->GetFaceGenAnimationData());

		if (!animData) {
			return;
		}

		RE::BSSpinLockGuard locker(animData->lock);

		switch (a_keyframeType) {
			case Keyframe::Type::Phoneme: {
				animData->phoneme2.SetValue(a_idx, a_value);
				break;
			}
			case Keyframe::Type::Expression: {
				animData->expressionOverride = false;
				animData->SetExpressionOverride(a_idx, a_value);
				animData->expressionOverride = true;
				break;
			}
			case Keyframe::Type::Modifier: {
				animData->modifier2.SetValue(a_idx, a_value);
				break;
			}
			case Keyframe::Type::Custom: {
				animData->custom2.SetValue(a_idx, a_value);
				break;
			}
		}
	}

	void PrintInfo(RE::TESObjectREFR* a_ref, Keyframe::Type a_keyframeType)
	{
		if (!a_ref) {
			return;
		}

		auto animData = reinterpret_cast<BSFaceGenAnimationData*>(a_ref->GetFaceGenAnimationData());

		if (!animData) {
			return;
		}

		auto console = RE::ConsoleLog::GetSingleton();

		if (!console) {
			return;
		}

		RE::BSSpinLockGuard locker(animData->lock);
		
		Keyframe* keyframe{ nullptr };

		switch (a_keyframeType) {
			case Keyframe::Type::Phoneme: {
				keyframe = &animData->phoneme2;
				break;
			}
			case Keyframe::Type::Expression: {
				keyframe = &animData->expression1;
				break;
			}
			case Keyframe::Type::Modifier: {
				keyframe = &animData->modifier2;
				break;
			}
			case Keyframe::Type::Custom: {
				keyframe = &animData->custom2;
				break;
			}
		}

		if (!keyframe) {
			return;
		}

		for (std::uint32_t i = 0; i < keyframe->count; ++i) {
			console->Print(fmt::format("{:2d}  {:3.0f}  {:s}", i, keyframe->values[i] * 100.0f, Keyframe::GetValueName(a_keyframeType, i)).c_str());
		}
	}

	void Reset(RE::TESObjectREFR* a_ref)
	{
		if (!a_ref) {
			return;
		}

		auto animData = reinterpret_cast<BSFaceGenAnimationData*>(a_ref->GetFaceGenAnimationData());

		if (!animData) {
			return;
		}

		RE::BSSpinLockGuard locker(animData->lock);

		animData->ClearExpressionOverride();
		animData->Reset(0.0f, true, true, true, false);
	}

	bool ModifyFaceGen_Execute(const RE::SCRIPT_PARAMETER* a_paramInfo, RE::SCRIPT_FUNCTION::ScriptData* a_scriptData, RE::TESObjectREFR* a_thisObj, RE::TESObjectREFR* a_containingObj, RE::Script* a_scriptObj, RE::ScriptLocals* a_locals, double& a_result, std::uint32_t& a_opcodeOffsetPtr)
	{
		using func_t = decltype(&ModifyFaceGen_Execute);
		REL::Relocation<func_t> func(ModifyFaceGen_ExecuteAddr);
		return func(a_paramInfo, a_scriptData, a_thisObj, a_containingObj, a_scriptObj, a_locals, a_result, a_opcodeOffsetPtr);
	}

	bool ModifyFaceGen_Execute_Hook(const RE::SCRIPT_PARAMETER* a_paramInfo, RE::SCRIPT_FUNCTION::ScriptData* a_scriptData, RE::TESObjectREFR* a_thisObj, RE::TESObjectREFR* a_containingObj, RE::Script* a_scriptObj, RE::ScriptLocals* a_locals, double& a_result, std::uint32_t& a_opcodeOffsetPtr)
	{
		auto thisObj = a_thisObj ? a_thisObj : RE::PlayerCharacter::GetSingleton();

		if (a_scriptData && a_paramInfo) {
			auto param1 = a_scriptData->numParams > 0 && a_paramInfo[0].paramType == RE::SCRIPT_PARAM_TYPE::kChar ? a_scriptData->GetChunk()->AsString() : nullptr;
			auto param2 = a_scriptData->numParams > 1 && a_paramInfo[1].paramType == RE::SCRIPT_PARAM_TYPE::kInt && param1 ? param1->GetNext()->AsInteger() : nullptr;
			auto param3 = a_scriptData->numParams > 2 && a_paramInfo[2].paramType == RE::SCRIPT_PARAM_TYPE::kInt && param2 ? param2->GetNext()->AsInteger() : nullptr;

			if (param1) {
				if (_strnicmp(param1->str, "expression", param1->length) == 0) {
					if (param2 && param3) {
						SetValue(thisObj, Keyframe::Type::Expression, param2->value, param3->value / 100.0f);
					} else if (!param2 && !param3) {
						PrintInfo(thisObj, Keyframe::Type::Expression);
					}
					return true;
				} else if (_strnicmp(param1->str, "modifier", param1->length) == 0) {
					if (param2 && param3) {
						SetValue(thisObj, Keyframe::Type::Modifier, param2->value, param3->value / 100.0f);
					} else if (!param2 && !param3) {
						PrintInfo(thisObj, Keyframe::Type::Modifier);
					}
					return true;
				} else if (_strnicmp(param1->str, "phoneme", param1->length) == 0) {
					if (param2 && param3) {
						SetValue(thisObj, Keyframe::Type::Phoneme, param2->value, param3->value / 100.0f);
					} else if (!param2 && !param3) {
						PrintInfo(thisObj, Keyframe::Type::Phoneme);
					}
					return true;
				} else if (_strnicmp(param1->str, "custom", param1->length) == 0) {
					if (param2 && param3) {
						SetValue(thisObj, Keyframe::Type::Custom, param2->value, param3->value / 100.0f);
					} else if (!param2 && !param3) {
						PrintInfo(thisObj, Keyframe::Type::Custom);
					}
					return true;
				} else if (_strnicmp(param1->str, "reset", param1->length) == 0) {
					Reset(thisObj);
					return true;
				}
			}
		}

		return ModifyFaceGen_Execute(a_paramInfo, a_scriptData, a_thisObj, a_containingObj, a_scriptObj, a_locals, a_result, a_opcodeOffsetPtr);
	}

	void Init()
	{
		ModifyFaceGen_ExecuteAddr = Offsets::ModifyFaceGen_Execute.address();

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&ModifyFaceGen_ExecuteAddr), reinterpret_cast<PVOID>(ModifyFaceGen_Execute_Hook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}

}