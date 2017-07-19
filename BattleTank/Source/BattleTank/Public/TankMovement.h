// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovement.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovement : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);


private:
	// Called from the path finding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankTrack *LeftTrack = nullptr;
	UTankTrack *RightTrack = nullptr;
	
};
