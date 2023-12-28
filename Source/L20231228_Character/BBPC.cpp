// Fill out your copyright notice in the Description page of Project Settings.


#include "BBPC.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void ABBPC::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem
		<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (SubSystem && DefaultIMC)
	{
		SubSystem->AddMappingContext(DefaultIMC,0);
	}
}
