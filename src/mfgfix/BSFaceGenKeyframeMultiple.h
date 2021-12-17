#pragma once

#include "BSFaceGenKeyframe.h"

namespace MfgFix
{
	class BSFaceGenKeyframeMultiple: public BSFaceGenKeyframe
	{
	public:
		enum class Type : std::int32_t
		{
			Undefined = -1,
			Phoneme,
			Expression,
			Modifier,
			Custom
		};

		enum Expression : std::uint32_t
		{
			DialogueAnger = 0,
			DialogueFear,
			DialogueHappy,
			DialogueSad,
			DialogueSurprise,
			DialoguePuzzled,
			DialogueDisgusted,
			MoodNeutral,
			MoodAnger,
			MoodFear,
			MoodHappy,
			MoodSad,
			MoodSurprise,
			MoodPuzzled,
			MoodDisgusted,
			CombatAnger,
			CombatShout
		};

		enum Modifier : std::uint32_t
		{
			BlinkLeft = 0,
			BlinkRight,
			BrowDownLeft,
			BrowDownRight,
			BrowInLeft,
			BrowInRight,
			BrowUpLeft,
			BrowUpRight,
			LookDown,
			LookLeft,
			LookRight,
			LookUp,
			SquintLeft,
			SquintRight,
			HeadPitch,
			HeadRoll,
			HeadYaw
		};

		enum Phoneme : std::uint32_t
		{
			Aah = 0,
			BigAah,
			BMP,
			ChJSh,
			DST,
			Eee,
			Eh,
			FV,
			I,
			K,
			N,
			Oh,
			OohQ,
			R,
			Th,
			W
		};

		enum Custom : std::uint32_t
		{
			SkinnyMorph = 0
		};

							~BSFaceGenKeyframeMultiple() override;																// 00
		bool				Unk_01(RE::BSTArray<BSFaceGenKeyframe*>& a_arr) override;											// 01
		bool				Interpolate(BSFaceGenKeyframe* a_keyframe1, BSFaceGenKeyframe* a_keyframe2, float a_k) override;	// 02
		bool				Interpolate(BSFaceGenKeyframe* a_keyframe, float a_k, bool a_ignoreSmall, bool a_copyBig) override;	// 03
		void				Reset(bool a_initToZero) override;																	// 04
		BSFaceGenKeyframe*	Clone() override;																					// 05
		void				Copy(BSFaceGenKeyframe* a_keyframe) override;														// 06
		bool				NotEqual(BSFaceGenKeyframe* a_keyframe) override;													// 07
		float				GetMaxValue() override;																				// 08
		bool				IsZero() override;																					// 09
		bool				TransitionUpdate(float a_timeDelta, BSFaceGenKeyframe* a_keyframe) override;						// 0A
		bool				NotZero() override;																					// 0B
		bool				IsKeyframeMultiple() override;																		// 0C { return true; };
		bool				IsKeyframeExclusive() override;																		// 0D { return false; };

							// Is value in range [0, 1].
		virtual bool		IsValueValid(std::uint32_t a_idx);																	// 0E
		virtual void		Allocate(std::uint32_t a_count, bool a_initToZero);													// 0F

		static std::string	GetValueName(Type a_type, std::uint32_t a_idx);

		void				SetValue(std::uint32_t a_idx, float a_value);
		void				Reset();

		float*			values;		// 10
		std::uint32_t	count;		// 18
		bool			isUpdated;	// 1C
		std::uint8_t	pad1D[3];	// 1D
	};

	static_assert(sizeof(BSFaceGenKeyframeMultiple) == 0x20);
}