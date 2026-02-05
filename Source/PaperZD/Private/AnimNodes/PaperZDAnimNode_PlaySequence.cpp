// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "AnimNodes/PaperZDAnimNode_PlaySequence.h"
#include "AnimSequences/Players/PaperZDAnimPlayer.h"
#include "AnimSequences/PaperZDAnimSequence_Flipbook.h"
#include "PaperZDAnimInstance.h"

#if ZD_VERSION_INLINED_CPP_SUPPORT
#include UE_INLINE_GENERATED_CPP_BY_NAME(PaperZDAnimNode_PlaySequence)
#endif

FPaperZDAnimNode_PlaySequence::FPaperZDAnimNode_PlaySequence()
	: AnimSequence(nullptr)
	, PlayRate(1.0f)
	, StartPosition(0.0f)
	, bLoopAnimation(true)
	, PlaybackTime(0.0f)
{}

void FPaperZDAnimNode_PlaySequence::OnInitialize(const FPaperZDAnimationInitContext& InitContext)
{
	InitPositions();
}

void FPaperZDAnimNode_PlaySequence::OnUpdate(const FPaperZDAnimationUpdateContext& UpdateContext)
{
	if (AnimSequence)
	{
		//Independent of the weight we have, we should update the playback, to avoid losing sync
		UPaperZDAnimPlayer* Player = UpdateContext.AnimInstance->GetPlayer();
		Player->TickPlayback(AnimSequence, PlaybackTime, UpdateContext.DeltaTime * PlayRate, bLoopAnimation, UpdateContext.AnimInstance, UpdateContext.Weight, false);
	}
}

void FPaperZDAnimNode_PlaySequence::OnEvaluate(FPaperZDAnimationPlaybackData& OutData)
{
	if (AnimSequence)
	{
		//Forcefully add the animation as the only present
		OutData.SetAnimation(AnimSequence, PlaybackTime);
	}
}

void FPaperZDAnimNode_PlaySequence::SetPlaybackTime(float NewPlaybackTime)
{
	PlaybackTime = NewPlaybackTime;
}

void FPaperZDAnimNode_PlaySequence::SetStartPosition(float NewStartPosition)
{
	if (AnimSequence)
	{
		StartPosition = FMath::Clamp<float>(NewStartPosition, 0.0f, GetTotalDuration());
	}
}

void FPaperZDAnimNode_PlaySequence::SetLoopAnimation(bool NewBLoopAnimation)
{
	bLoopAnimation = NewBLoopAnimation;
}

float FPaperZDAnimNode_PlaySequence::GetTotalDuration() const
{
	if (AnimSequence)
	{
		return AnimSequence->GetTotalDuration();
	}
	return 0.0f;
}

void FPaperZDAnimNode_PlaySequence::Reset()
{
	if (AnimSequence)
	{
		StartPosition = 0.0f;
		InitPositions();
	}
}

void FPaperZDAnimNode_PlaySequence::InitPositions()
{
	if (AnimSequence)
	{
		//Initialize the starting time
		const float SeqDuration = GetTotalDuration();
		const float StartTime = PlayRate > 0.0f ? StartPosition : SeqDuration - StartPosition;
		PlaybackTime = FMath::Clamp(StartTime, 0.0f, SeqDuration);
	}
}
