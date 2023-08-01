// Copyright Özdemir Özdemir 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:
	void AimTowardsCrosshair();

};
