// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "ToonTanksPlayerController.h"
#include "Tank.h"
#include "Tower.h"

#include "Kismet/GameplayStatics.h"


void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (ToonTanksPlayerController)
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
			GameOver(false);
			
		}
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
		TargetTowers--;

		if (TargetTowers == 0)
		{
			GameOver(true);
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
	
}

void AToonTanksGameMode::HandleGameStart()
{
	TargetTowers = GetTargetTowerCount();
	Tank = CastChecked<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = CastChecked<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();
	
	if (ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnabledTimerHandle;

		FTimerDelegate PlayerEnabledTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true
		);

		GetWorldTimerManager().SetTimer(
			PlayerEnabledTimerHandle,
			PlayerEnabledTimerDelegate,
			StartDelay,
			false
		);
	}
}

int32 AToonTanksGameMode::GetTargetTowerCount()
{
	TArray<AActor*> Towers;

	UGameplayStatics::GetAllActorsOfClass(
		this,
		ATower::StaticClass(),
		Towers
	);

	return Towers.Num();
}
