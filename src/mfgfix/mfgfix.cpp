#include "mfgfix.h"
#include "Settings.h"
#include "BSFaceGenAnimationData.h"
#include "ConsoleCommands.h"
#include "SettingsPapyrus.h"
#include "MfgConsoleFunc.h"
#include "Misc.h"


namespace MfgFix
{
	void Init()
	{
		SettingsNS::Init();
		BSFaceGenAnimationDataNS::Init();
		ConsoleCommands::Init();
		SettingsPapyrus::Init();
		MfgConsoleFunc::Init();
		Misc::Init();
	}
}