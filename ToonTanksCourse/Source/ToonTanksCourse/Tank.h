// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BP_BasePawn.h"
#include "InputActionValue.h"
#include "Tank.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class TOONTANKSCOURSE_API ATank : public ABP_BasePawn
{
	GENERATED_BODY()
public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	
	// Input system components
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank Settings")
	UInputMappingContext* DefaultMappingContext;

	// Input actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank Settings")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank Settings")
	UInputAction* TurnAction;

	
	
private:
	
	UPROPERTY(VisibleAnywhere, Category = "Tank Settings")
	class UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, Category = "Tank Settings")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float Speed = 400.0f;
	
	void Move(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);

	
};
