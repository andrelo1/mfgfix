#pragma once

namespace MfgFix
{
	struct Settings
	{
		struct EyesBlinking
		{
			float	fBlinkDownTime{ 0.04f };
			float	fBlinkUpTime{ 0.14f };
			float	fBlinkDelayMin{ 0.5f };
			float	fBlinkDelayMax{ 8.0f };
		};

		struct EyesMovement
		{
			float	fTrackSpeed{ 5.0f };
			float	fTrackEyeXY{ 28.0f };
			float	fTrackEyeZ{ 20.0f };
			float	fEyeHeadingMinOffsetEmotionAngry{ -0.05f };
			float	fEyeHeadingMaxOffsetEmotionAngry{ 0.05f };
			float	fEyePitchMinOffsetEmotionAngry{ -0.05f };
			float	fEyePitchMaxOffsetEmotionAngry{ 0.1f };
			float	fEyeOffsetDelayMinEmotionAngry{ 0.5f };
			float	fEyeOffsetDelayMaxEmotionAngry{ 3.0f };
			float	fEyeHeadingMinOffsetEmotionHappy{ -0.1f };
			float	fEyeHeadingMaxOffsetEmotionHappy{ 0.1f };
			float	fEyePitchMinOffsetEmotionHappy{ -0.05f };
			float	fEyePitchMaxOffsetEmotionHappy{ 0.1f };
			float	fEyeOffsetDelayMinEmotionHappy{ 0.5f };
			float	fEyeOffsetDelayMaxEmotionHappy{ 4.0f };
			float	fEyeHeadingMinOffsetEmotionSurprise{ -0.1f };
			float	fEyeHeadingMaxOffsetEmotionSurprise{ 0.1f };
			float	fEyePitchMinOffsetEmotionSurprise{ -0.05f };
			float	fEyePitchMaxOffsetEmotionSurprise{ 0.1f };
			float	fEyeOffsetDelayMinEmotionSurprise{ 0.5f };
			float	fEyeOffsetDelayMaxEmotionSurprise{ 4.0f };
			float	fEyeHeadingMinOffsetEmotionSad{ -0.1f };
			float	fEyeHeadingMaxOffsetEmotionSad{ 0.1f };
			float	fEyePitchMinOffsetEmotionSad{ -0.05f };
			float	fEyePitchMaxOffsetEmotionSad{ -0.015f };
			float	fEyeOffsetDelayMinEmotionSad{ 2.0f };
			float	fEyeOffsetDelayMaxEmotionSad{ 3.0f };
			float	fEyeHeadingMinOffsetEmotionFear{ -0.1f };
			float	fEyeHeadingMaxOffsetEmotionFear{ 0.1f };
			float	fEyePitchMinOffsetEmotionFear{ 0.01f };
			float	fEyePitchMaxOffsetEmotionFear{ 0.01f };
			float	fEyeOffsetDelayMinEmotionFear{ 0.5f };
			float	fEyeOffsetDelayMaxEmotionFear{ 1.5f };
			float	fEyeHeadingMinOffsetEmotionNeutral{ -0.1f };
			float	fEyeHeadingMaxOffsetEmotionNeutral{ 0.1f };
			float	fEyePitchMinOffsetEmotionNeutral{ -0.025f };
			float	fEyePitchMaxOffsetEmotionNeutral{ 0.1f };
			float	fEyeOffsetDelayMinEmotionNeutral{ 0.5f };
			float	fEyeOffsetDelayMaxEmotionNeutral{ 4.0f };
			float	fEyeHeadingMinOffsetEmotionPuzzled{ 0.0f };
			float	fEyeHeadingMaxOffsetEmotionPuzzled{ 0.0f };
			float	fEyePitchMinOffsetEmotionPuzzled{ 0.0f };
			float	fEyePitchMaxOffsetEmotionPuzzled{ 0.0f };
			float	fEyeOffsetDelayMinEmotionPuzzled{ 3.0f };
			float	fEyeOffsetDelayMaxEmotionPuzzled{ 3.0f };
			float	fEyeHeadingMinOffsetEmotionDisgusted{ 0.0f };
			float	fEyeHeadingMaxOffsetEmotionDisgusted{ 0.0f };
			float	fEyePitchMinOffsetEmotionDisgusted{ 0.0f };
			float	fEyePitchMaxOffsetEmotionDisgusted{ 0.0f };
			float	fEyeOffsetDelayMinEmotionDisgusted{ 3.0f };
			float	fEyeOffsetDelayMaxEmotionDisgusted{ 3.0f };
			float	fEyeHeadingMinOffsetEmotionCombatAnger{ 0.0f };
			float	fEyeHeadingMaxOffsetEmotionCombatAnger{ 0.0f };
			float	fEyePitchMinOffsetEmotionCombatAnger{ 0.0f };
			float	fEyePitchMaxOffsetEmotionCombatAnger{ 0.0f };
			float	fEyeOffsetDelayMinEmotionCombatAnger{ 3.0f };
			float	fEyeOffsetDelayMaxEmotionCombatAnger{ 3.0f };
			float	fEyeHeadingMinOffsetEmotionCombatShout{ 0.0f };
			float	fEyeHeadingMaxOffsetEmotionCombatShout{ 0.0f };
			float	fEyePitchMinOffsetEmotionCombatShout{ 0.0f };
			float	fEyePitchMaxOffsetEmotionCombatShout{ 0.0f };
			float	fEyeOffsetDelayMinEmotionCombatShout{ 3.0f };
			float	fEyeOffsetDelayMaxEmotionCombatShout{ 3.0f };
		};

		static Settings&	Get();

		void	Read();
		void	Write();

		EyesBlinking	eyesBlinking;
		EyesMovement	eyesMovement;
	};
}