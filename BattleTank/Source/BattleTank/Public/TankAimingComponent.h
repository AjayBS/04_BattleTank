// Copyright EmbraceIT Ltd.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for firing status
UENUM()
enum class EFiringStatus : uint8 
{ 
	Locked, 
	Aiming, 
	Reloading 
};

// Forward declaration
class UTankBarrel; 
class UTankTurret;

// Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:		
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);
	
	void AimAt(FVector HitLocation, float LaunchSpeed);	

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Aiming;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
