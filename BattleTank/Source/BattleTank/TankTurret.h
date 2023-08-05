// Copyright Ozdemir Ozdemir 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include "TankTurret.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void SetRotateDirection(float Dir);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaximumRotationSpeed = 40;
};
