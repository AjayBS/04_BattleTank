// Copyright EmbraceIT Ltd.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovement.h"

void UTankMovement::Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovement::IntendMoveForward(float Throw) 
{	
	if (!ensure(LeftTrack || !RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovement::IntendTurnRight(float Throw) 
{
	if (!ensure(LeftTrack || !RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovement::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call super as we are replacing the functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName,*MoveVelocityString);
}