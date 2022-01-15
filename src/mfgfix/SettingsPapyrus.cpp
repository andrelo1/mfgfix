#include "SettingsPapyrus.h"
#include "Settings.h"

namespace MfgFix::SettingsPapyrus
{
	void Save(RE::StaticFunctionTag*)
	{
		Settings::Get().WriteIni();
	}

	float GetFBlinkDownTime(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesBlinking.fBlinkDownTime;
	}

	void SetFBlinkDownTime(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesBlinking.fBlinkDownTime = a_value;
	}

	float GetFBlinkUpTime(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesBlinking.fBlinkUpTime;
	}

	void SetFBlinkUpTime(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesBlinking.fBlinkUpTime = a_value;
	}

	float GetFBlinkDelayMin(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesBlinking.fBlinkDelayMin;
	}

	void SetFBlinkDelayMin(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesBlinking.fBlinkDelayMin = a_value;
	}

	float GetFBlinkDelayMax(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesBlinking.fBlinkDelayMax;
	}

	void SetFBlinkDelayMax(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesBlinking.fBlinkDelayMax = a_value;
	}

	float GetFTrackSpeed(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fTrackSpeed;
	}

	void SetFTrackSpeed(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fTrackSpeed = a_value;
	}

	float GetFTrackEyeXY(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fTrackEyeXY;
	}

	void SetFTrackEyeXY(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fTrackEyeXY = a_value;
	}

	float GetFTrackEyeZ(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fTrackEyeZ;
	}

	void SetFTrackEyeZ(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fTrackEyeZ = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionAngry(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionAngry;
	}

	void SetFEyeHeadingMinOffsetEmotionAngry(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionAngry = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionAngry(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionAngry;
	}

	void SetFEyeHeadingMaxOffsetEmotionAngry(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionAngry = a_value;
	}

	float GetFEyePitchMinOffsetEmotionAngry(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionAngry;
	}

	void SetFEyePitchMinOffsetEmotionAngry(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionAngry = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionAngry(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionAngry;
	}

	void SetFEyePitchMaxOffsetEmotionAngry(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionAngry = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionAngry(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionAngry;
	}

	void SetFEyeOffsetDelayMinEmotionAngry(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionAngry = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionAngry(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionAngry;
	}

	void SetFEyeOffsetDelayMaxEmotionAngry(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionAngry = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionHappy(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionHappy;
	}

	void SetFEyeHeadingMinOffsetEmotionHappy(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionHappy = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionHappy(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionHappy;
	}

	void SetFEyeHeadingMaxOffsetEmotionHappy(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionHappy = a_value;
	}

	float GetFEyePitchMinOffsetEmotionHappy(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionHappy;
	}

	void SetFEyePitchMinOffsetEmotionHappy(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionHappy = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionHappy(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionHappy;
	}

	void SetFEyePitchMaxOffsetEmotionHappy(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionHappy = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionHappy(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionHappy;
	}

	void SetFEyeOffsetDelayMinEmotionHappy(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionHappy = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionHappy(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionHappy;
	}

	void SetFEyeOffsetDelayMaxEmotionHappy(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionHappy = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionSurprise(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionSurprise;
	}

	void SetFEyeHeadingMinOffsetEmotionSurprise(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionSurprise = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionSurprise(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionSurprise;
	}

	void SetFEyeHeadingMaxOffsetEmotionSurprise(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionSurprise = a_value;
	}

	float GetFEyePitchMinOffsetEmotionSurprise(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionSurprise;
	}

	void SetFEyePitchMinOffsetEmotionSurprise(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionSurprise = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionSurprise(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionSurprise;
	}

	void SetFEyePitchMaxOffsetEmotionSurprise(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionSurprise = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionSurprise(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionSurprise;
	}

	void SetFEyeOffsetDelayMinEmotionSurprise(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionSurprise = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionSurprise(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionSurprise;
	}

	void SetFEyeOffsetDelayMaxEmotionSurprise(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionSurprise = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionSad(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionSad;
	}

	void SetFEyeHeadingMinOffsetEmotionSad(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionSad = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionSad(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionSad;
	}

	void SetFEyeHeadingMaxOffsetEmotionSad(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionSad = a_value;
	}

	float GetFEyePitchMinOffsetEmotionSad(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionSad;
	}

	void SetFEyePitchMinOffsetEmotionSad(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionSad = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionSad(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionSad;
	}

	void SetFEyePitchMaxOffsetEmotionSad(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionSad = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionSad(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionSad;
	}

	void SetFEyeOffsetDelayMinEmotionSad(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionSad = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionSad(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionSad;
	}

	void SetFEyeOffsetDelayMaxEmotionSad(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionSad = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionFear(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionFear;
	}

	void SetFEyeHeadingMinOffsetEmotionFear(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionFear = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionFear(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionFear;
	}

	void SetFEyeHeadingMaxOffsetEmotionFear(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionFear = a_value;
	}

	float GetFEyePitchMinOffsetEmotionFear(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionFear;
	}

	void SetFEyePitchMinOffsetEmotionFear(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionFear = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionFear(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionFear;
	}

	void SetFEyePitchMaxOffsetEmotionFear(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionFear = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionFear(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionFear;
	}

	void SetFEyeOffsetDelayMinEmotionFear(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionFear = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionFear(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionFear;
	}

	void SetFEyeOffsetDelayMaxEmotionFear(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionFear = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionNeutral(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionNeutral;
	}

	void SetFEyeHeadingMinOffsetEmotionNeutral(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionNeutral = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionNeutral(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionNeutral;
	}

	void SetFEyeHeadingMaxOffsetEmotionNeutral(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionNeutral = a_value;
	}

	float GetFEyePitchMinOffsetEmotionNeutral(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionNeutral;
	}

	void SetFEyePitchMinOffsetEmotionNeutral(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionNeutral = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionNeutral(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionNeutral;
	}

	void SetFEyePitchMaxOffsetEmotionNeutral(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionNeutral = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionNeutral(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionNeutral;
	}

	void SetFEyeOffsetDelayMinEmotionNeutral(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionNeutral = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionNeutral(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionNeutral;
	}

	void SetFEyeOffsetDelayMaxEmotionNeutral(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionNeutral = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionPuzzled(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionPuzzled;
	}

	void SetFEyeHeadingMinOffsetEmotionPuzzled(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionPuzzled = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionPuzzled(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionPuzzled;
	}

	void SetFEyeHeadingMaxOffsetEmotionPuzzled(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionPuzzled = a_value;
	}

	float GetFEyePitchMinOffsetEmotionPuzzled(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionPuzzled;
	}

	void SetFEyePitchMinOffsetEmotionPuzzled(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionPuzzled = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionPuzzled(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionPuzzled;
	}

	void SetFEyePitchMaxOffsetEmotionPuzzled(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionPuzzled = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionPuzzled(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionPuzzled;
	}

	void SetFEyeOffsetDelayMinEmotionPuzzled(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionPuzzled = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionPuzzled(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionPuzzled;
	}

	void SetFEyeOffsetDelayMaxEmotionPuzzled(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionPuzzled = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionDisgusted(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionDisgusted;
	}

	void SetFEyeHeadingMinOffsetEmotionDisgusted(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionDisgusted = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionDisgusted(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionDisgusted;
	}

	void SetFEyeHeadingMaxOffsetEmotionDisgusted(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionDisgusted = a_value;
	}

	float GetFEyePitchMinOffsetEmotionDisgusted(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionDisgusted;
	}

	void SetFEyePitchMinOffsetEmotionDisgusted(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionDisgusted = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionDisgusted(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionDisgusted;
	}

	void SetFEyePitchMaxOffsetEmotionDisgusted(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionDisgusted = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionDisgusted(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionDisgusted;
	}

	void SetFEyeOffsetDelayMinEmotionDisgusted(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionDisgusted = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionDisgusted(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionDisgusted;
	}

	void SetFEyeOffsetDelayMaxEmotionDisgusted(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionDisgusted = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionCombatAnger(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionCombatAnger;
	}

	void SetFEyeHeadingMinOffsetEmotionCombatAnger(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionCombatAnger = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionCombatAnger(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionCombatAnger;
	}

	void SetFEyeHeadingMaxOffsetEmotionCombatAnger(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionCombatAnger = a_value;
	}

	float GetFEyePitchMinOffsetEmotionCombatAnger(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionCombatAnger;
	}

	void SetFEyePitchMinOffsetEmotionCombatAnger(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionCombatAnger = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionCombatAnger(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionCombatAnger;
	}

	void SetFEyePitchMaxOffsetEmotionCombatAnger(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionCombatAnger = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionCombatAnger(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionCombatAnger;
	}

	void SetFEyeOffsetDelayMinEmotionCombatAnger(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionCombatAnger = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionCombatAnger(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionCombatAnger;
	}

	void SetFEyeOffsetDelayMaxEmotionCombatAnger(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionCombatAnger = a_value;
	}

	float GetFEyeHeadingMinOffsetEmotionCombatShout(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionCombatShout;
	}

	void SetFEyeHeadingMinOffsetEmotionCombatShout(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMinOffsetEmotionCombatShout = a_value;
	}

	float GetFEyeHeadingMaxOffsetEmotionCombatShout(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionCombatShout;
	}

	void SetFEyeHeadingMaxOffsetEmotionCombatShout(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeHeadingMaxOffsetEmotionCombatShout = a_value;
	}

	float GetFEyePitchMinOffsetEmotionCombatShout(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionCombatShout;
	}

	void SetFEyePitchMinOffsetEmotionCombatShout(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMinOffsetEmotionCombatShout = a_value;
	}

	float GetFEyePitchMaxOffsetEmotionCombatShout(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionCombatShout;
	}

	void SetFEyePitchMaxOffsetEmotionCombatShout(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyePitchMaxOffsetEmotionCombatShout = a_value;
	}

	float GetFEyeOffsetDelayMinEmotionCombatShout(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionCombatShout;
	}

	void SetFEyeOffsetDelayMinEmotionCombatShout(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMinEmotionCombatShout = a_value;
	}

	float GetFEyeOffsetDelayMaxEmotionCombatShout(RE::StaticFunctionTag*)
	{
		return Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionCombatShout;
	}

	void SetFEyeOffsetDelayMaxEmotionCombatShout(RE::StaticFunctionTag*, float a_value)
	{
		Settings::Get().eyesMovement.fEyeOffsetDelayMaxEmotionCombatShout = a_value;
	}

	void Init()
	{
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("Save", "MFGFIX_Settings", Save);
			a_vm->RegisterFunction("GetFBlinkDownTime", "MFGFIX_Settings", GetFBlinkDownTime);
			a_vm->RegisterFunction("SetFBlinkDownTime", "MFGFIX_Settings", SetFBlinkDownTime);
			a_vm->RegisterFunction("GetFBlinkUpTime", "MFGFIX_Settings", GetFBlinkUpTime);
			a_vm->RegisterFunction("SetFBlinkUpTime", "MFGFIX_Settings", SetFBlinkUpTime);
			a_vm->RegisterFunction("GetFBlinkDelayMin", "MFGFIX_Settings", GetFBlinkDelayMin);
			a_vm->RegisterFunction("SetFBlinkDelayMin", "MFGFIX_Settings", SetFBlinkDelayMin);
			a_vm->RegisterFunction("GetFBlinkDelayMax", "MFGFIX_Settings", GetFBlinkDelayMax);
			a_vm->RegisterFunction("SetFBlinkDelayMax", "MFGFIX_Settings", SetFBlinkDelayMax);
			a_vm->RegisterFunction("GetFTrackSpeed", "MFGFIX_Settings", GetFTrackSpeed);
			a_vm->RegisterFunction("SetFTrackSpeed", "MFGFIX_Settings", SetFTrackSpeed);
			a_vm->RegisterFunction("GetFTrackEyeXY", "MFGFIX_Settings", GetFTrackEyeXY);
			a_vm->RegisterFunction("SetFTrackEyeXY", "MFGFIX_Settings", SetFTrackEyeXY);
			a_vm->RegisterFunction("GetFTrackEyeZ", "MFGFIX_Settings", GetFTrackEyeZ);
			a_vm->RegisterFunction("SetFTrackEyeZ", "MFGFIX_Settings", SetFTrackEyeZ);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionAngry", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionAngry);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionAngry", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionAngry);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionAngry", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionAngry);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionAngry", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionAngry);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionAngry", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionAngry);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionAngry", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionAngry);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionAngry", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionAngry);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionAngry", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionAngry);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionAngry", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionAngry);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionAngry", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionAngry);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionAngry", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionAngry);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionAngry", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionAngry);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionHappy", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionHappy);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionHappy", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionHappy);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionHappy", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionHappy);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionHappy", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionHappy);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionHappy", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionHappy);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionHappy", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionHappy);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionHappy", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionHappy);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionHappy", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionHappy);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionHappy", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionHappy);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionHappy", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionHappy);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionHappy", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionHappy);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionHappy", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionHappy);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionSurprise", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionSurprise);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionSurprise", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionSurprise);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionSurprise", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionSurprise);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionSurprise", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionSurprise);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionSurprise", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionSurprise);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionSurprise", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionSurprise);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionSurprise", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionSurprise);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionSurprise", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionSurprise);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionSurprise", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionSurprise);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionSurprise", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionSurprise);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionSurprise", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionSurprise);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionSurprise", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionSurprise);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionSad", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionSad);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionSad", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionSad);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionSad", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionSad);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionSad", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionSad);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionSad", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionSad);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionSad", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionSad);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionSad", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionSad);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionSad", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionSad);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionSad", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionSad);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionSad", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionSad);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionSad", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionSad);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionSad", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionSad);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionFear", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionFear);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionFear", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionFear);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionFear", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionFear);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionFear", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionFear);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionFear", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionFear);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionFear", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionFear);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionFear", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionFear);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionFear", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionFear);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionFear", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionFear);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionFear", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionFear);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionFear", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionFear);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionFear", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionFear);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionNeutral", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionNeutral);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionNeutral", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionNeutral);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionNeutral", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionNeutral);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionNeutral", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionNeutral);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionNeutral", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionNeutral);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionNeutral", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionNeutral);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionNeutral", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionNeutral);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionNeutral", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionNeutral);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionNeutral", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionNeutral);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionNeutral", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionNeutral);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionNeutral", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionNeutral);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionNeutral", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionNeutral);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionPuzzled", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionPuzzled);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionPuzzled", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionPuzzled);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionPuzzled", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionPuzzled);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionPuzzled", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionPuzzled);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionPuzzled", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionPuzzled);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionPuzzled", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionPuzzled);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionPuzzled", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionPuzzled);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionPuzzled", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionPuzzled);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionPuzzled", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionPuzzled);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionPuzzled", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionPuzzled);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionPuzzled", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionPuzzled);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionPuzzled", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionPuzzled);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionDisgusted", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionDisgusted);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionDisgusted", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionDisgusted);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionDisgusted", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionDisgusted);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionDisgusted", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionDisgusted);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionDisgusted", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionDisgusted);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionDisgusted", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionDisgusted);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionDisgusted", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionDisgusted);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionDisgusted", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionDisgusted);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionDisgusted", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionDisgusted);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionDisgusted", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionDisgusted);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionDisgusted", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionDisgusted);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionDisgusted", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionDisgusted);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionCombatAnger", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionCombatAnger", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionCombatAnger", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionCombatAnger", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionCombatAnger", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionCombatAnger", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionCombatAnger", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionCombatAnger", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionCombatAnger);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionCombatAnger", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionCombatAnger);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionCombatAnger", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionCombatAnger);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionCombatAnger", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionCombatAnger);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionCombatAnger", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionCombatAnger);
			a_vm->RegisterFunction("GetFEyeHeadingMinOffsetEmotionCombatShout", "MFGFIX_Settings", GetFEyeHeadingMinOffsetEmotionCombatShout);
			a_vm->RegisterFunction("SetFEyeHeadingMinOffsetEmotionCombatShout", "MFGFIX_Settings", SetFEyeHeadingMinOffsetEmotionCombatShout);
			a_vm->RegisterFunction("GetFEyeHeadingMaxOffsetEmotionCombatShout", "MFGFIX_Settings", GetFEyeHeadingMaxOffsetEmotionCombatShout);
			a_vm->RegisterFunction("SetFEyeHeadingMaxOffsetEmotionCombatShout", "MFGFIX_Settings", SetFEyeHeadingMaxOffsetEmotionCombatShout);
			a_vm->RegisterFunction("GetFEyePitchMinOffsetEmotionCombatShout", "MFGFIX_Settings", GetFEyePitchMinOffsetEmotionCombatShout);
			a_vm->RegisterFunction("SetFEyePitchMinOffsetEmotionCombatShout", "MFGFIX_Settings", SetFEyePitchMinOffsetEmotionCombatShout);
			a_vm->RegisterFunction("GetFEyePitchMaxOffsetEmotionCombatShout", "MFGFIX_Settings", GetFEyePitchMaxOffsetEmotionCombatShout);
			a_vm->RegisterFunction("SetFEyePitchMaxOffsetEmotionCombatShout", "MFGFIX_Settings", SetFEyePitchMaxOffsetEmotionCombatShout);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMinEmotionCombatShout", "MFGFIX_Settings", GetFEyeOffsetDelayMinEmotionCombatShout);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMinEmotionCombatShout", "MFGFIX_Settings", SetFEyeOffsetDelayMinEmotionCombatShout);
			a_vm->RegisterFunction("GetFEyeOffsetDelayMaxEmotionCombatShout", "MFGFIX_Settings", GetFEyeOffsetDelayMaxEmotionCombatShout);
			a_vm->RegisterFunction("SetFEyeOffsetDelayMaxEmotionCombatShout", "MFGFIX_Settings", SetFEyeOffsetDelayMaxEmotionCombatShout);

			return true;
		});
	}
}