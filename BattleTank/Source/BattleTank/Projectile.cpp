//Copyright Ozdemir Ozdemir 2023

#include "Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponentCode"));
	MovementComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed)
{
	MovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	MovementComponent->Activate(false);
}

