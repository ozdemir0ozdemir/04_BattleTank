// Copyright Özdemir Özdemir 2023

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	Super::Tick(DeltaTime);
	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// Fire if read
		//ControlledTank->Fire(); // TODO limit firing rate
	}
}





