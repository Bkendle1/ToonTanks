// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Component Settings")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, Category="Component Settings")
	class UCameraComponent* CameraComp;

	void Move(float Value);

	UPROPERTY(EditAnywhere, Category="Movement")
	float MoveSpeed = 500.f;

	void Turn(float Value);

	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate = 100.f;

	APlayerController* TankPlayerController;
};
