// Copyright Ozdemir Ozdemir 2023
#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"

#include "TankTrack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Per Track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Driving")
	float TrackMaxDrivingForce = 400000;


};
