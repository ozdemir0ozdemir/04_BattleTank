// Copyright Ozdemir Ozdemir 2023
#pragma once

#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	virtual void Tick(float DeltaTime) override;
	void LaunchProjectile(float Speed);

protected:
	virtual void BeginPlay() override;

private:
	UProjectileMovementComponent* MovementComponent = nullptr;
};
