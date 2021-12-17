#pragma once


namespace MfgFix::Offsets
{

	namespace
	{
		static constexpr REL::ID ModifyFaceGen_Execute(static_cast<std::uint64_t>(23017));
		static constexpr REL::ID GetExpressionName(static_cast<std::uint64_t>(27007));
		static constexpr REL::ID GetModifierName(static_cast<std::uint64_t>(27008));
		static constexpr REL::ID GetPhonemeName(static_cast<std::uint64_t>(27009));
		static constexpr REL::ID GetCustomName(static_cast<std::uint64_t>(27010));
	}

	namespace BSFaceGenAnimationData
	{
		static constexpr REL::ID KeyframesUpdate(static_cast<std::uint64_t>(26598));
		static constexpr REL::ID SetExpressionOverride(static_cast<std::uint64_t>(26594));
		static constexpr REL::ID sub_3DB770(static_cast<std::uint64_t>(26593));
		static constexpr REL::ID Reset(static_cast<std::uint64_t>(26586));
	}

	namespace BSFaceGenNiNode
	{
		static constexpr REL::ID sub_3F1800(static_cast<std::uint64_t>(26998));
		static constexpr REL::ID sub_3F0C90(static_cast<std::uint64_t>(26988));
	}

	namespace Papyrus
	{
		namespace Actor
		{
			static constexpr REL::ID SetExpressionOverride(static_cast<std::uint64_t>(54748));
		}
	}
}