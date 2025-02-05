// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime) override;	

	virtual void SetPawn(APawn *InPawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	// How close can the AI tank get close to the player
	float AcceptanceRadius = 8000.f;

	UFUNCTION()
	void OnPossesedTankDeath();
};
