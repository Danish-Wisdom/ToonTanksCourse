// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BP_BasePawn.generated.h"

UCLASS()
class TOONTANKSCOURSE_API ABP_BasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABP_BasePawn();

	
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn Variables", meta = (AllowPrivateAccess = true))
	float Speed = 400.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CompVars", meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CompVars", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CompVars", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CompVars", meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint;


	// We will finish this section in the next stream. G2G.
};
