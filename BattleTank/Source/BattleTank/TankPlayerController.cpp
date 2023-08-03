// Copyright Özdemir Özdemir 2023

#include "TankPlayerController.h"
#include "Tank.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No controlled tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank label is :  %s"), *(ControlledTank->GetActorLabel()));
	}

	
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {return;}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) 
	{
		GetControlledTank()->AimAt(HitLocation);
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(HitLocation, LookDirection);
	}

	
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // Discarded

	bool bProjectionResult = DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

	//DrawDebugLine(GetWorld(), CameraWorldLocation, CameraWorldLocation + LookDirection * 5000, FColor::Red, false, -1.0f, 0U, 5.0f);

	return bProjectionResult;
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	bool bLineTraceResult = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		PlayerCameraManager->GetCameraLocation(),
		(PlayerCameraManager->GetCameraLocation() + LookDirection * LineTraceRange),
		ECollisionChannel::ECC_Visibility
	);

	AActor* HittedActor = HitResult.GetActor();
	if (HittedActor)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}



