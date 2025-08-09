// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

}



void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATank::Move);
		
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ATank::Turn);
		
		EnhancedInputComponent->BindAction(BoostAction, ETriggerEvent::Started, this, &ATank::Boost);
		EnhancedInputComponent->BindAction(BoostAction, ETriggerEvent::Completed, this, &ATank::EndBoost);
		
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &ATank::Fire);
	}
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = CastChecked<APlayerController>(GetController());
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef)
	{
		FHitResult Hit;
		PlayerControllerRef->GetHitResultUnderCursor(
			ECC_Visibility,
			false,
			Hit);

		DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 30, 12, FColor::Red, false, -1);

		RotateTurret(Hit.ImpactPoint);
		
	}
}


void ATank::Move(const FInputActionValue& Value)
{
	FString ValueString = Value.ToString();
	UE_LOG(LogTemp, Display, TEXT("MoveForward: %s"), *ValueString);

	FVector DeltaLocation(0.f);
	float InputValue = Value.Get<float>();

	InputValue = InputValue * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	
	DeltaLocation.Y = InputValue;

	AddActorLocalOffset(DeltaLocation, true); 
}

void ATank::Turn(const FInputActionValue& Value)
{
	FString ValueString = Value.ToString();
	UE_LOG(LogTemp, Display, TEXT("Turn Input: %s"), *ValueString);

	FRotator DeltaRotation(0.f);
	float InputValue = Value.Get<float>();

	InputValue = InputValue * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;

	DeltaRotation.Yaw = InputValue;

	AddActorLocalRotation(DeltaRotation);
}

void ATank::Boost(const FInputActionValue& Value)
{
	Speed = (Speed * BoostRate);
}

void ATank::EndBoost()
{
	Speed = (Speed / BoostRate);
}



