// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
private:
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrossHair();

	// Return an out parameter, true if it hits landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333f;

	float LineTraceRange = 1000000.0f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
};
