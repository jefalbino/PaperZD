// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "FPaperZDAnimStateInfo.generated.h"

USTRUCT(BlueprintType)
struct PAPERZD_API FPaperZDAnimStateInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	FName StateMachineName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	int32 NodeStateIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PaperZD")
	float NodeStateTime;

public:
	//ctor
	FPaperZDAnimStateInfo()
	{}
};