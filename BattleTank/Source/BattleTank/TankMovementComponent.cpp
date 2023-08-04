// Copyright Özdemir Özdemir 2023


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
