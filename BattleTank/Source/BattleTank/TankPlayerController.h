// Copyright Ozdemir Ozdemir 2023
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
	
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float LineTraceRange = 1000000;
};
