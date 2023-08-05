// Copyright Ozdemir Ozdemir 2023
#pragma once

#include "BattleTank.h"
#include "AIController.h"

#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	float AcceptanceRadius = 3000;
	UTankAimingComponent* AimingComponent = nullptr;
	
};
