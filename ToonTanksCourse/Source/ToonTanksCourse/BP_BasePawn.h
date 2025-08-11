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

	void HandleDestruction();
	
	



protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed = 10.f;
	
	void RotateTurret(FVector Target);

	void Fire();

	

private:
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Toon Object", meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Toon Object", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Toon Object", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Toon Object", meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = true))
	TSubclassOf<class AProjectile> ProjectileClass;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompVars", meta = (AllowPrivateAccess = true))
	// int32 NumberOfSpawnPoints = 1;
	//
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CompVars", meta = (AllowPrivateAccess = true))
	// TArray<USceneComponent*> SpawnPoints;
	
};
