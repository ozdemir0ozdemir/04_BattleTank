// Copyright Ozdemir Ozdemir 2023
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"

class ATank;

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
	
};
