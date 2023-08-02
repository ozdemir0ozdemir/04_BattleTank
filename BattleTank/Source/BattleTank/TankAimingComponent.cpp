// Copyright Özdemir Özdemir 2023

#include "TankAimingComponent.h"

#include "TankBarrel.h"
#include "Camera/CameraComponent.h"
#include <Kismet/GameplayStatics.h>


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s aim at %s"), *GetActorLabel(), *HitLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Camera Comp : %s"),*GetOwner()->FindComponentByClass<UCameraComponent>()->GetComponentLocation().ToString() );
	//DrawDebugSphere(GetWorld(), GetOwner()->FindComponentByClass<UCameraComponent>()->GetComponentLocation(), 20, 16, FColor::Magenta);
	
	DrawDebugLine(
		GetWorld(),
		//GetOwner()->FindComponentByClass<UCameraComponent>()->GetComponentLocation() + GetOwner()->FindComponentByClass<UCameraComponent>()->GetComponentRotation().Vector() * 100,
		Barrel->GetSocketLocation(FName("Projectile")),
		WorldSpaceAim,
		FColor::Red,
		false,
		-1.0f,
		0U,
		10.0f
	);

	

	if (!Barrel) { return; }
	FVector LaunchVelocity(0, 0, 0);
	TArray<AActor*> Actors;
	
	bool bSuggestionResult = UGameplayStatics::SuggestProjectileVelocity(
		this,
		LaunchVelocity,
		Barrel->GetSocketLocation(FName("Projectile")),
		WorldSpaceAim,
		LaunchSpeed, 
		false, 
		0, 
		0.0f, 
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		Actors, 
		false
	);
	if (bSuggestionResult) {
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

	}	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Current rotation and aim dir difference
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
}



void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}


