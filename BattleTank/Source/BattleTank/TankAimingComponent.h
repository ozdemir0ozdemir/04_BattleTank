// Copyright Özdemir Özdemir 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	virtual void BeginPlay() override;



private:	
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

		
};
