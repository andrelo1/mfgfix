#include "BSFaceGenKeyframeMultiple.h"
#include "Offsets.h"

namespace MfgFix
{
	namespace {
		const char* GetExpressionName(std::uint32_t a_expression)
		{
			using func_t = decltype(&GetExpressionName);
			REL::Relocation<func_t> func(Offsets::GetExpressionName);
			return func(a_expression);
		}

		const char* GetModifierName(std::uint32_t a_modifier)
		{
			using func_t = decltype(&GetModifierName);
			REL::Relocation<func_t> func(Offsets::GetModifierName);
			return func(a_modifier);
		}

		const char* GetPhonemeName(std::uint32_t a_phoneme)
		{
			using func_t = decltype(&GetPhonemeName);
			REL::Relocation<func_t> func(Offsets::GetPhonemeName);
			return func(a_phoneme);
		}

		const char* GetCustomName(std::uint32_t a_custom)
		{
			using func_t = decltype(&GetCustomName);
			REL::Relocation<func_t> func(Offsets::GetCustomName);
			return func(a_custom);
		}
	}

	void BSFaceGenKeyframeMultiple::SetValue(std::uint32_t a_idx, float a_value)
	{
		if (a_idx < count) {
			values[a_idx] = a_value;
			isUpdated = false;
		}
	}

	void BSFaceGenKeyframeMultiple::Reset()
	{
		std::fill_n(values, count, 0.0f);
		isUpdated = false;
	}

	std::string BSFaceGenKeyframeMultiple::GetValueName(Type a_type, std::uint32_t a_idx)
	{
		const char* name{ nullptr };

		switch (a_type) {
			case Type::Expression: {
				name = GetExpressionName(a_idx);
				break;
			}
			case Type::Modifier: {
				name = GetModifierName(a_idx);
				break;
			}
			case Type::Phoneme:	{
				name = GetPhonemeName(a_idx);
				break;
			}
			case Type::Custom: {
				name = GetCustomName(a_idx);
				break;
			}
		}

		return name ? name : "";
	}
}