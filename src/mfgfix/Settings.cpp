#include "Settings.h"
#include <SimpleIni.h>

namespace MfgFix
{
	namespace
	{
		std::filesystem::path GetIniPath()
		{
			wchar_t buf[4096] = L"";

			std::uint32_t size = GetModuleFileNameW(NULL, buf, static_cast<DWORD>(std::size(buf)));

			if (size == 0 || size == std::size(buf)) {
				return "";
			}

			std::filesystem::path path{ buf };
					
			return path.replace_filename(L"Data\\SKSE\\Plugins\\mfgfix.ini");
		}
	}

	Settings& Settings::Get()
	{
		static Settings settings;

		return settings;
	}

	void Settings::Read()
	{
		CSimpleIniA ini;
		auto path = GetIniPath();

		if (ini.LoadFile(path.c_str()) != SI_OK) {
			return;
		}

		eyesBlinking.fBlinkDownTime = static_cast<float>(ini.GetDoubleValue("EyesBlinking", "fBlinkDownTime", eyesBlinking.fBlinkDownTime));
		eyesBlinking.fBlinkUpTime = static_cast<float>(ini.GetDoubleValue("EyesBlinking", "fBlinkUpTime", eyesBlinking.fBlinkUpTime));
		eyesBlinking.fBlinkDelayMin = static_cast<float>(ini.GetDoubleValue("EyesBlinking", "fBlinkDelayMin", eyesBlinking.fBlinkDelayMin));
		eyesBlinking.fBlinkDelayMax = static_cast<float>(ini.GetDoubleValue("EyesBlinking", "fBlinkDelayMax", eyesBlinking.fBlinkDelayMax));
		eyesMovement.fTrackSpeed = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fTrackSpeed", eyesMovement.fTrackSpeed));
		eyesMovement.fTrackEyeXY = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fTrackEyeXY", eyesMovement.fTrackEyeXY));
		eyesMovement.fTrackEyeZ = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fTrackEyeZ", eyesMovement.fTrackEyeZ));
		eyesMovement.fEyeHeadingMinOffsetEmotionAngry = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionAngry", eyesMovement.fEyeHeadingMinOffsetEmotionAngry));
		eyesMovement.fEyeHeadingMaxOffsetEmotionAngry = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionAngry", eyesMovement.fEyeHeadingMaxOffsetEmotionAngry));
		eyesMovement.fEyePitchMinOffsetEmotionAngry = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionAngry", eyesMovement.fEyePitchMinOffsetEmotionAngry));
		eyesMovement.fEyePitchMaxOffsetEmotionAngry = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionAngry", eyesMovement.fEyePitchMaxOffsetEmotionAngry));
		eyesMovement.fEyeOffsetDelayMinEmotionAngry = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionAngry", eyesMovement.fEyeOffsetDelayMinEmotionAngry));
		eyesMovement.fEyeOffsetDelayMaxEmotionAngry = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionAngry", eyesMovement.fEyeOffsetDelayMaxEmotionAngry));
		eyesMovement.fEyeHeadingMinOffsetEmotionHappy = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionHappy", eyesMovement.fEyeHeadingMinOffsetEmotionHappy));
		eyesMovement.fEyeHeadingMaxOffsetEmotionHappy = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionHappy", eyesMovement.fEyeHeadingMaxOffsetEmotionHappy));
		eyesMovement.fEyePitchMinOffsetEmotionHappy = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionHappy", eyesMovement.fEyePitchMinOffsetEmotionHappy));
		eyesMovement.fEyePitchMaxOffsetEmotionHappy = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionHappy", eyesMovement.fEyePitchMaxOffsetEmotionHappy));
		eyesMovement.fEyeOffsetDelayMinEmotionHappy = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionHappy", eyesMovement.fEyeOffsetDelayMinEmotionHappy));
		eyesMovement.fEyeOffsetDelayMaxEmotionHappy = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionHappy", eyesMovement.fEyeOffsetDelayMaxEmotionHappy));
		eyesMovement.fEyeHeadingMinOffsetEmotionSurprise = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionSurprise", eyesMovement.fEyeHeadingMinOffsetEmotionSurprise));
		eyesMovement.fEyeHeadingMaxOffsetEmotionSurprise = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionSurprise", eyesMovement.fEyeHeadingMaxOffsetEmotionSurprise));
		eyesMovement.fEyePitchMinOffsetEmotionSurprise = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionSurprise", eyesMovement.fEyePitchMinOffsetEmotionSurprise));
		eyesMovement.fEyePitchMaxOffsetEmotionSurprise = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionSurprise", eyesMovement.fEyePitchMaxOffsetEmotionSurprise));
		eyesMovement.fEyeOffsetDelayMinEmotionSurprise = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionSurprise", eyesMovement.fEyeOffsetDelayMinEmotionSurprise));
		eyesMovement.fEyeOffsetDelayMaxEmotionSurprise = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionSurprise", eyesMovement.fEyeOffsetDelayMaxEmotionSurprise));
		eyesMovement.fEyeHeadingMinOffsetEmotionSad = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionSad", eyesMovement.fEyeHeadingMinOffsetEmotionSad));
		eyesMovement.fEyeHeadingMaxOffsetEmotionSad = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionSad", eyesMovement.fEyeHeadingMaxOffsetEmotionSad));
		eyesMovement.fEyePitchMinOffsetEmotionSad = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionSad", eyesMovement.fEyePitchMinOffsetEmotionSad));
		eyesMovement.fEyePitchMaxOffsetEmotionSad = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionSad", eyesMovement.fEyePitchMaxOffsetEmotionSad));
		eyesMovement.fEyeOffsetDelayMinEmotionSad = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionSad", eyesMovement.fEyeOffsetDelayMinEmotionSad));
		eyesMovement.fEyeOffsetDelayMaxEmotionSad = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionSad", eyesMovement.fEyeOffsetDelayMaxEmotionSad));
		eyesMovement.fEyeHeadingMinOffsetEmotionFear = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionFear", eyesMovement.fEyeHeadingMinOffsetEmotionFear));
		eyesMovement.fEyeHeadingMaxOffsetEmotionFear = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionFear", eyesMovement.fEyeHeadingMaxOffsetEmotionFear));
		eyesMovement.fEyePitchMinOffsetEmotionFear = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionFear", eyesMovement.fEyePitchMinOffsetEmotionFear));
		eyesMovement.fEyePitchMaxOffsetEmotionFear = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionFear", eyesMovement.fEyePitchMaxOffsetEmotionFear));
		eyesMovement.fEyeOffsetDelayMinEmotionFear = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionFear", eyesMovement.fEyeOffsetDelayMinEmotionFear));
		eyesMovement.fEyeOffsetDelayMaxEmotionFear = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionFear", eyesMovement.fEyeOffsetDelayMaxEmotionFear));
		eyesMovement.fEyeHeadingMinOffsetEmotionNeutral = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionNeutral", eyesMovement.fEyeHeadingMinOffsetEmotionNeutral));
		eyesMovement.fEyeHeadingMaxOffsetEmotionNeutral = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionNeutral", eyesMovement.fEyeHeadingMaxOffsetEmotionNeutral));
		eyesMovement.fEyePitchMinOffsetEmotionNeutral = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionNeutral", eyesMovement.fEyePitchMinOffsetEmotionNeutral));
		eyesMovement.fEyePitchMaxOffsetEmotionNeutral = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionNeutral", eyesMovement.fEyePitchMaxOffsetEmotionNeutral));
		eyesMovement.fEyeOffsetDelayMinEmotionNeutral = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionNeutral", eyesMovement.fEyeOffsetDelayMinEmotionNeutral));
		eyesMovement.fEyeOffsetDelayMaxEmotionNeutral = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionNeutral", eyesMovement.fEyeOffsetDelayMaxEmotionNeutral));
		eyesMovement.fEyeHeadingMinOffsetEmotionPuzzled = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionPuzzled", eyesMovement.fEyeHeadingMinOffsetEmotionPuzzled));
		eyesMovement.fEyeHeadingMaxOffsetEmotionPuzzled = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionPuzzled", eyesMovement.fEyeHeadingMaxOffsetEmotionPuzzled));
		eyesMovement.fEyePitchMinOffsetEmotionPuzzled = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionPuzzled", eyesMovement.fEyePitchMinOffsetEmotionPuzzled));
		eyesMovement.fEyePitchMaxOffsetEmotionPuzzled = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionPuzzled", eyesMovement.fEyePitchMaxOffsetEmotionPuzzled));
		eyesMovement.fEyeOffsetDelayMinEmotionPuzzled = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionPuzzled", eyesMovement.fEyeOffsetDelayMinEmotionPuzzled));
		eyesMovement.fEyeOffsetDelayMaxEmotionPuzzled = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionPuzzled", eyesMovement.fEyeOffsetDelayMaxEmotionPuzzled));
		eyesMovement.fEyeHeadingMinOffsetEmotionDisgusted = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionDisgusted", eyesMovement.fEyeHeadingMinOffsetEmotionDisgusted));
		eyesMovement.fEyeHeadingMaxOffsetEmotionDisgusted = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionDisgusted", eyesMovement.fEyeHeadingMaxOffsetEmotionDisgusted));
		eyesMovement.fEyePitchMinOffsetEmotionDisgusted = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionDisgusted", eyesMovement.fEyePitchMinOffsetEmotionDisgusted));
		eyesMovement.fEyePitchMaxOffsetEmotionDisgusted = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionDisgusted", eyesMovement.fEyePitchMaxOffsetEmotionDisgusted));
		eyesMovement.fEyeOffsetDelayMinEmotionDisgusted = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionDisgusted", eyesMovement.fEyeOffsetDelayMinEmotionDisgusted));
		eyesMovement.fEyeOffsetDelayMaxEmotionDisgusted = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionDisgusted", eyesMovement.fEyeOffsetDelayMaxEmotionDisgusted));
		eyesMovement.fEyeHeadingMinOffsetEmotionCombatAnger = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionCombatAnger", eyesMovement.fEyeHeadingMinOffsetEmotionCombatAnger));
		eyesMovement.fEyeHeadingMaxOffsetEmotionCombatAnger = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionCombatAnger", eyesMovement.fEyeHeadingMaxOffsetEmotionCombatAnger));
		eyesMovement.fEyePitchMinOffsetEmotionCombatAnger = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionCombatAnger", eyesMovement.fEyePitchMinOffsetEmotionCombatAnger));
		eyesMovement.fEyePitchMaxOffsetEmotionCombatAnger = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionCombatAnger", eyesMovement.fEyePitchMaxOffsetEmotionCombatAnger));
		eyesMovement.fEyeOffsetDelayMinEmotionCombatAnger = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionCombatAnger", eyesMovement.fEyeOffsetDelayMinEmotionCombatAnger));
		eyesMovement.fEyeOffsetDelayMaxEmotionCombatAnger = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionCombatAnger", eyesMovement.fEyeOffsetDelayMaxEmotionCombatAnger));
		eyesMovement.fEyeHeadingMinOffsetEmotionCombatShout = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionCombatShout", eyesMovement.fEyeHeadingMinOffsetEmotionCombatShout));
		eyesMovement.fEyeHeadingMaxOffsetEmotionCombatShout = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionCombatShout", eyesMovement.fEyeHeadingMaxOffsetEmotionCombatShout));
		eyesMovement.fEyePitchMinOffsetEmotionCombatShout = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionCombatShout", eyesMovement.fEyePitchMinOffsetEmotionCombatShout));
		eyesMovement.fEyePitchMaxOffsetEmotionCombatShout = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionCombatShout", eyesMovement.fEyePitchMaxOffsetEmotionCombatShout));
		eyesMovement.fEyeOffsetDelayMinEmotionCombatShout = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionCombatShout", eyesMovement.fEyeOffsetDelayMinEmotionCombatShout));
		eyesMovement.fEyeOffsetDelayMaxEmotionCombatShout = static_cast<float>(ini.GetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionCombatShout", eyesMovement.fEyeOffsetDelayMaxEmotionCombatShout));
	}

	void Settings::Write()
	{
		CSimpleIniA ini;
		auto path = GetIniPath();

		ini.LoadFile(path.c_str());

		ini.SetDoubleValue("EyesBlinking", "fBlinkDownTime", eyesBlinking.fBlinkDownTime);
		ini.SetDoubleValue("EyesBlinking", "fBlinkUpTime", eyesBlinking.fBlinkUpTime);
		ini.SetDoubleValue("EyesBlinking", "fBlinkDelayMin", eyesBlinking.fBlinkDelayMin);
		ini.SetDoubleValue("EyesBlinking", "fBlinkDelayMax", eyesBlinking.fBlinkDelayMax);
		ini.SetDoubleValue("EyesMovement", "fTrackSpeed", eyesMovement.fTrackSpeed);
		ini.SetDoubleValue("EyesMovement", "fTrackEyeXY", eyesMovement.fTrackEyeXY);
		ini.SetDoubleValue("EyesMovement", "fTrackEyeZ", eyesMovement.fTrackEyeZ);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionAngry", eyesMovement.fEyeHeadingMinOffsetEmotionAngry);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionAngry", eyesMovement.fEyeHeadingMaxOffsetEmotionAngry);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionAngry", eyesMovement.fEyePitchMinOffsetEmotionAngry);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionAngry", eyesMovement.fEyePitchMaxOffsetEmotionAngry);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionAngry", eyesMovement.fEyeOffsetDelayMinEmotionAngry);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionAngry", eyesMovement.fEyeOffsetDelayMaxEmotionAngry);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionHappy", eyesMovement.fEyeHeadingMinOffsetEmotionHappy);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionHappy", eyesMovement.fEyeHeadingMaxOffsetEmotionHappy);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionHappy", eyesMovement.fEyePitchMinOffsetEmotionHappy);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionHappy", eyesMovement.fEyePitchMaxOffsetEmotionHappy);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionHappy", eyesMovement.fEyeOffsetDelayMinEmotionHappy);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionHappy", eyesMovement.fEyeOffsetDelayMaxEmotionHappy);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionSurprise", eyesMovement.fEyeHeadingMinOffsetEmotionSurprise);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionSurprise", eyesMovement.fEyeHeadingMaxOffsetEmotionSurprise);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionSurprise", eyesMovement.fEyePitchMinOffsetEmotionSurprise);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionSurprise", eyesMovement.fEyePitchMaxOffsetEmotionSurprise);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionSurprise", eyesMovement.fEyeOffsetDelayMinEmotionSurprise);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionSurprise", eyesMovement.fEyeOffsetDelayMaxEmotionSurprise);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionSad", eyesMovement.fEyeHeadingMinOffsetEmotionSad);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionSad", eyesMovement.fEyeHeadingMaxOffsetEmotionSad);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionSad", eyesMovement.fEyePitchMinOffsetEmotionSad);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionSad", eyesMovement.fEyePitchMaxOffsetEmotionSad);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionSad", eyesMovement.fEyeOffsetDelayMinEmotionSad);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionSad", eyesMovement.fEyeOffsetDelayMaxEmotionSad);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionFear", eyesMovement.fEyeHeadingMinOffsetEmotionFear);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionFear", eyesMovement.fEyeHeadingMaxOffsetEmotionFear);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionFear", eyesMovement.fEyePitchMinOffsetEmotionFear);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionFear", eyesMovement.fEyePitchMaxOffsetEmotionFear);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionFear", eyesMovement.fEyeOffsetDelayMinEmotionFear);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionFear", eyesMovement.fEyeOffsetDelayMaxEmotionFear);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionNeutral", eyesMovement.fEyeHeadingMinOffsetEmotionNeutral);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionNeutral", eyesMovement.fEyeHeadingMaxOffsetEmotionNeutral);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionNeutral", eyesMovement.fEyePitchMinOffsetEmotionNeutral);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionNeutral", eyesMovement.fEyePitchMaxOffsetEmotionNeutral);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionNeutral", eyesMovement.fEyeOffsetDelayMinEmotionNeutral);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionNeutral", eyesMovement.fEyeOffsetDelayMaxEmotionNeutral);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionPuzzled", eyesMovement.fEyeHeadingMinOffsetEmotionPuzzled);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionPuzzled", eyesMovement.fEyeHeadingMaxOffsetEmotionPuzzled);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionPuzzled", eyesMovement.fEyePitchMinOffsetEmotionPuzzled);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionPuzzled", eyesMovement.fEyePitchMaxOffsetEmotionPuzzled);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionPuzzled", eyesMovement.fEyeOffsetDelayMinEmotionPuzzled);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionPuzzled", eyesMovement.fEyeOffsetDelayMaxEmotionPuzzled);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionDisgusted", eyesMovement.fEyeHeadingMinOffsetEmotionDisgusted);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionDisgusted", eyesMovement.fEyeHeadingMaxOffsetEmotionDisgusted);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionDisgusted", eyesMovement.fEyePitchMinOffsetEmotionDisgusted);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionDisgusted", eyesMovement.fEyePitchMaxOffsetEmotionDisgusted);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionDisgusted", eyesMovement.fEyeOffsetDelayMinEmotionDisgusted);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionDisgusted", eyesMovement.fEyeOffsetDelayMaxEmotionDisgusted);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionCombatAnger", eyesMovement.fEyeHeadingMinOffsetEmotionCombatAnger);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionCombatAnger", eyesMovement.fEyeHeadingMaxOffsetEmotionCombatAnger);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionCombatAnger", eyesMovement.fEyePitchMinOffsetEmotionCombatAnger);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionCombatAnger", eyesMovement.fEyePitchMaxOffsetEmotionCombatAnger);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionCombatAnger", eyesMovement.fEyeOffsetDelayMinEmotionCombatAnger);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionCombatAnger", eyesMovement.fEyeOffsetDelayMaxEmotionCombatAnger);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMinOffsetEmotionCombatShout", eyesMovement.fEyeHeadingMinOffsetEmotionCombatShout);
		ini.SetDoubleValue("EyesMovement", "fEyeHeadingMaxOffsetEmotionCombatShout", eyesMovement.fEyeHeadingMaxOffsetEmotionCombatShout);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMinOffsetEmotionCombatShout", eyesMovement.fEyePitchMinOffsetEmotionCombatShout);
		ini.SetDoubleValue("EyesMovement", "fEyePitchMaxOffsetEmotionCombatShout", eyesMovement.fEyePitchMaxOffsetEmotionCombatShout);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMinEmotionCombatShout", eyesMovement.fEyeOffsetDelayMinEmotionCombatShout);
		ini.SetDoubleValue("EyesMovement", "fEyeOffsetDelayMaxEmotionCombatShout", eyesMovement.fEyeOffsetDelayMaxEmotionCombatShout);

		ini.SaveFile(path.c_str());
	}
}
