// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_BasePawn.h"

#include "Tank.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABP_BasePawn::ABP_BasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));

	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

    // Find a way to change this into an array in order to implement the ability to have multiple spawn points
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);


	// for (int32 index = 0; index < NumberOfSpawnPoints; index++)
	// {
	// 	USceneComponent* SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point " +  index));
	// 	SpawnPoint->SetupAttachment(TurretMesh);
	//
	// 	SpawnPoints.Add(SpawnPoint);
	// }
}

void ABP_BasePawn::RotateTurret(FVector Target)
{
	FVector ToTarget = Target - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.0f);

	TurretMesh->SetWorldRotation(LookAtRotation);
}



