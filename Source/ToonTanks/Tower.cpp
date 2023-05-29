// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
	
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	// Get reference to tank
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition,FireRate,true);
}


void ATower::CheckFireCondition()
{
	if(InFireRange())
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if(Tank != nullptr)
	{
		float const Distance = FVector::Distance(GetActorLocation(), Tank->GetActorLocation());
		if(Distance <= FireRange)
		{
			return true;
		}
	}
	return false;
}
