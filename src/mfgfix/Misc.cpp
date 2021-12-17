#include "Offsets.h"
#include "Misc.h"

namespace MfgFix::Misc
{
	void Init()
	{
		// Allow to set expressions for dead npcs.
		REL::safe_fill(Offsets::BSFaceGenAnimationData::sub_3DB770.address() + 0x004A, 0x90, 0x0D);
		// Fix papyrus SetExpressionOverride not working with aiMood 0.
		REL::safe_write(Offsets::Papyrus::Actor::SetExpressionOverride.address() + 0x001A, static_cast<std::uint16_t>(0x9001));
		REL::safe_write(Offsets::Papyrus::Actor::SetExpressionOverride.address() + 0x002A, static_cast<std::uint8_t>(0x10));
		// Remove code that sometimes may cause ctd because it doesn't test parent node for null.
		REL::safe_fill(Offsets::BSFaceGenNiNode::sub_3F0C90.address() + 0x0395, 0x90, 0x0F);
	}
}