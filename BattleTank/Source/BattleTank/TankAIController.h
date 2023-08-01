// Copyright Özdemir Özdemir 2023

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"

#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
private:
	ATank* GetPlayerTank() const;
	
};
