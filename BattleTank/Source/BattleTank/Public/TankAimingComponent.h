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
class AProjectile;

// Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:		
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();
	
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;
	FVector AimDirection;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; // ALternative https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;
};
