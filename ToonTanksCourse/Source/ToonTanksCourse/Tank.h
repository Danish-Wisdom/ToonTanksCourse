// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BP_BasePawn.h"
#include "Tank.generated.h"


/**
 * 
 */
UCLASS()
class TOONTANKSCOURSE_API ATank : public ABP_BasePawn
{
	GENERATED_BODY()
public:
	ATank();

private:
	UPROPERTY(VisibleAnywhere, Category = "Tank Settings")
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = "Tank Settings")
	class USpringArmComponent* SpringArm;
};
