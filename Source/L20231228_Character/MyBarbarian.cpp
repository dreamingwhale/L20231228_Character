// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBarbarian.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyBarbarian::AMyBarbarian()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComponent);


	GetMesh()->SetRelativeLocation(FVector(0,0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0,-90.0f, 0));


	SpringArmComponent->TargetArmLength = 500.0f;
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bEnableCameraLag = true;
	
}

// Called when the game starts or when spawned
void AMyBarbarian::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBarbarian::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBarbarian::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UEIC)
	{
		UEIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMyBarbarian::Jump);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &AMyBarbarian::StopJumping);
		
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMyBarbarian::Move);
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMyBarbarian::Look);
	}

}

void AMyBarbarian::Move(const FInputActionValue& Value)
{
	FVector2D Dir = Value.Get<FVector2D>();

	FRotator CameraRotation = GetControlRotation();
	FRotator DirectionRotation = FRotator(0, CameraRotation.Yaw, 0);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(DirectionRotation);
	FVector RightVector = UKismetMathLibrary::GetRightVector(DirectionRotation);

	AddMovementInput(ForwardVector,Dir.Y);
	AddMovementInput(RightVector,Dir.X);
}

void AMyBarbarian::Look(const FInputActionValue& Value)
{
	FVector2D Rotation = Value.Get<FVector2D>();
	AddControllerYawInput(Rotation.X);
	AddControllerPitchInput(Rotation.Y);
}


