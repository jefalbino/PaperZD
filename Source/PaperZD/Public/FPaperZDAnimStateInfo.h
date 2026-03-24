// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "FPaperZDAnimStateInfo.generated.h"

USTRUCT(BlueprintType)
struct PAPERZD_API FPaperZDAnimStateInfo
{
	GENERATED_BODY()

	UPROPERTY(Meta = (IgnoreForMemberInitializationTest), EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	FName StateMachineName;

	UPROPERTY(Meta = (IgnoreForMemberInitializationTest), EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	int32 StateIndex;

	UPROPERTY(Meta = (IgnoreForMemberInitializationTest), EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	float PlaybackTime;

	UPROPERTY(Meta = (IgnoreForMemberInitializationTest), EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	float DeltaTime;

public:
	//ctor
	FPaperZDAnimStateInfo()
	{}
};