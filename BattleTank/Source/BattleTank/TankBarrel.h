// Copyright Özdemir Özdemir 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include "TankBarrel.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1  +1
	void Elevate(float RelativeSpeed); 

private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSeconds = 10;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40;


	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0;

};
