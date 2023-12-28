// Fill out your copyright notice in the Description page of Project Settings.


#include "BBAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBBAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	ACharacter* MyCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(MyCharacter))
	{
		Speed = MyCharacter->GetCharacterMovement()->Velocity.Size2D();
	}

}
