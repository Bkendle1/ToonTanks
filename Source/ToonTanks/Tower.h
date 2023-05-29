// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	// Forward declare ATank class
	class ATank* Tank;

	UPROPERTY(EditDefaultsOnly, Category="Attack")
	float FireRange = 1000.f;

	FTimerHandle FireRateTimerHandle;
	
	UPROPERTY(EditDefaultsOnly, Category="Attack")
	float FireRate = 2.f;

	void CheckFireCondition();
	bool InFireRange();
};
