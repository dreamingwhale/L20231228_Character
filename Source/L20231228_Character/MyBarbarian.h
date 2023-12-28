// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyBarbarian.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputAction;

UCLASS()
class L20231228_CHARACTER_API AMyBarbarian : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyBarbarian();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <USpringArmComponent> SpringArmComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr <UInputAction> IA_Jump;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr <UInputAction> IA_Move;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr <UInputAction> IA_Look;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

};
