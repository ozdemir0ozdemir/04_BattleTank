// Copyright Özdemir Özdemir 2023

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank possesed with AI : %s"), *(GetControlledTank()->GetActorLabel()));
	UE_LOG(LogTemp, Warning, TEXT("Tank found player controller : %s"), *(GetPlayerTank()->GetActorLabel()));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		// TODO Move towards the player
		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if read
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController) { return nullptr; }

	ATank* Player = Cast<ATank>(PlayerController->GetPawn());
	if (!Player) { return nullptr; }

	return Player;
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


