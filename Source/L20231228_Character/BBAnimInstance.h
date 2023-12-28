// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BBAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class L20231228_CHARACTER_API UBBAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "Stat")
	float Speed;
};
