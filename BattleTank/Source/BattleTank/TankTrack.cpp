// Copyright Özdemir Özdemir 2023


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	if (Throttle != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Throttle : %f"), *GetName(), Throttle)

		FVector	ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
		FVector ForceLocation = GetComponentLocation();
		UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
		
		
	}
	
}
