#pragma once

#include "BSFaceGenKeyframeMultiple.h"

namespace MfgFix
{
	class BSFaceGenAnimationData: public RE::NiExtraData
	{
	public:
		using Keyframe = BSFaceGenKeyframeMultiple;
		using Expression = Keyframe::Expression;
		using Phoneme = Keyframe::Phoneme;
		using Modifier = Keyframe::Modifier;

		enum class EyesBlinkingStage : std::uint32_t
		{
			BlinkDelay = 0,
			BlinkDown,
			BlinkUp,
			WaitForLookDown,
			BlinkDownAndWait1,
			BlinkDownAndWait2
		};

		struct DialogueData
		{
			struct Unk28
			{
				std::int32_t	unk0;		// 00
				std::int32_t	unk4;		// 04
				std::uint8_t	unk8[0x8];	// 08
				void*			unk10;		// 10
				void*			unk18;		// 18
				std::uint8_t	unk20;		// 20
			};

			std::uint8_t	unk0[0xC];		// 00
			std::uint32_t	refCount;		// 0C
			std::uint8_t	unk10[0x18];	// 10
			Unk28*			unk28;			// 28
		};

		Keyframe*				transitionTarget;	// 18 used to animate transition between expressions
		Keyframe				expression1;		// 20 used by console command and SetExpressionOverride
		Keyframe				expression2;		// 40 unused?
		Keyframe				modifier2;			// 60 used by console command
		Keyframe				phoneme2;			// 80 used by console command
		Keyframe				custom2;			// A0 used by console command
		Keyframe				expression3;		// C0 final values
		Keyframe				modifier1;			// E0 dialogue values
		Keyframe				modifier3;			// 100 final values
		Keyframe				phoneme1;			// 120 dialogue values
		Keyframe				phoneme3;			// 140 final values
		Keyframe				custom1;			// 160 unused?
		Keyframe				custom3;			// 180 final values
		float					unk1A0;				// 1A0
		float					unk1A4;				// 1A4
		float					unk1A8;				// 1A8
		std::uint32_t			unk1AC;				// 1AC
		std::uint32_t			unk1B0;				// 1B0
		std::uint32_t			nk1B4;				// 1B4
		std::uint32_t			unk1B8;				// 1B8
		float					eyesHeading;		// 1BC eyesHeadingBase + eyesHeadingOffset
		float					eyesPitch;			// 1C0 eyesPitchBase + eyesPitchOffset
		std::uint32_t			pad1C4;				// 1C4
		std::uint64_t			unk1C8;				// 1C8
		std::uint8_t			unk1D0;				// 1D0
		std::uint8_t			unk1D1;				// 1D1
		std::uint8_t			nk1D2;				// 1D2
		std::uint8_t			unk1D3;				// 1D3
		float					eyesHeadingBase;	// 1D4
		float					eyesPitchBase;		// 1D8
		std::uint32_t			unk1DC;				// 1DC
		std::uint32_t			unk1E0;				// 1E0
		std::uint32_t			unk1E4;				// 1E4
		std::uint32_t			unk1E8;				// 1E8
		std::uint32_t			unk1EC;				// 1EC
		std::uint32_t			unk1F0;				// 1F0
		std::uint32_t			unk1F4;				// 1F4
		std::uint32_t			unk1F8;				// 1F8
		std::uint32_t			unk1FC;				// 1FC
		EyesBlinkingStage		eyesBlinkingStage;	// 200
		float					eyesBlinkingTimer;	// 204
		float					eyesOffsetTimer;	// 208 
		float					eyesHeadingOffset;	// 20C
		float					eyesPitchOffset;	// 210
		std::uint8_t			unk214;				// 214
		std::uint8_t			unk215;				// 215
		std::uint8_t			unk216;				// 216
		bool					unk217;				// 217
		std::uint8_t			unk218;				// 218
		std::uint8_t			unk219;				// 219
		std::uint8_t			unk21A;				// 21A
		std::uint8_t			unk21B;				// 21B
		std::uint8_t			unk21C;				// 21C
		std::uint8_t			unk21D;				// 21D
		bool					expressionOverride;	// 21E
		std::uint8_t			unk21F;				// 21F
		mutable RE::BSSpinLock	lock;				// 220
		DialogueData*			dialogueData;		// 228
		

		void			SetExpressionOverride(std::uint32_t a_idx, float a_value);
		void			ClearExpressionOverride();
		void			Reset(float a_timer, bool a_resetExpression, bool a_resetModifierAndPhoneme, bool a_resetCustom, bool a_closeEyes);
		std::uint32_t	GetActiveExpression() const;
		void			DialogueModifiersUpdate(float a_timeDelta);
		void			DialoguePhonemesUpdate(float a_timeDelta);
		void			CheckAndReleaseDialogueData();
		void			EyesBlinkingUpdate(float a_timeDelta);
		void			EyesMovementUpdate(float a_timeDelta);
		void			EyesDirectionUpdate(float a_timeDelta);
		bool			KeyframesUpdateHook(float a_timeDelta, bool a_updateBlinking);

		static void		Init();
	};

	static_assert(sizeof(BSFaceGenAnimationData) == 0x230);
}