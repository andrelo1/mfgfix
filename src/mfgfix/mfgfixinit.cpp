#include "mfgfixinit.h"
#include "Settings.h"
#include "BSFaceGenAnimationData.h"
#include "ConsoleCommands.h"
#include "SettingsPapyrus.h"
#include "MfgConsoleFunc.h"
#include "Offsets.h"


namespace MfgFix
{
	void Init()
	{
		Settings::Get().Read();

		BSFaceGenAnimationData::Init();
		ConsoleCommands::Init();

		// Papyrus
		SettingsPapyrus::Register();
		MfgConsoleFunc::Register();

		// Misc

		// allow expression change for dead npcs
		REL::safe_fill(Offsets::BSFaceGenAnimationData::sub_3DB770.address() + 0x004A, 0x90, 0x0D);
		// fix papyrus function SetExpressionOverride that didn't work with aiMood 0
		REL::safe_write(Offsets::Papyrus::Actor::SetExpressionOverride.address() + 0x001A, static_cast<std::uint16_t>(0x9001));
		REL::safe_write(Offsets::Papyrus::Actor::SetExpressionOverride.address() + 0x002A, static_cast<std::uint8_t>(0x10));
		// disable code that sometimes cause ctd because of missing check for null parent node
		REL::safe_fill(Offsets::BSFaceGenNiNode::sub_3F0C90.address() + 0x0395, 0x90, 0x0F);
	}
}