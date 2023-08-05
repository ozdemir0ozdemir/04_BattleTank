// Copyright Ozdemir Ozdemir 2023

#include "TankMovementComponent.h"

#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (Throw == 0) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("%s Move Forward : %f"), *GetName(), Throw)

	if (LeftTrack && RightTrack)
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);
	}
	
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (LeftTrack && RightTrack)
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(-Throw);
	}
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{

	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector TankMoveVelocity = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, TankMoveVelocity);
	IntendMoveForward(ForwardThrow );

	float TankRotateVelocity  = FVector::CrossProduct(TankForward, TankMoveVelocity).Z;

	IntendTurnRight(TankRotateVelocity );

	//UE_LOG(LogTemp, Warning, TEXT("Move Velocity : %f"), ForwardThrow);
}
