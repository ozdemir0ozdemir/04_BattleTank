// Copyright Ozdemir Ozdemir 2023

#include "TankMovementComponent.h"

#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet && RightTrackToSet)) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (Throw == 0) { return; }

	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) 
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector TankMoveVelocity = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, TankMoveVelocity);
	IntendMoveForward(ForwardThrow );

	float TankRotateVelocity  = FVector::CrossProduct(TankForward, TankMoveVelocity).Z;
	IntendTurnRight(TankRotateVelocity );
}
