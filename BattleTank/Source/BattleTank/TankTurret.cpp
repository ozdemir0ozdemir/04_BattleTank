// Copyright Ozdemir Ozdemir 2023

#include "TankTurret.h"

void UTankTurret::SetRotateDirection(float Dir)
{
	//UE_LOG(LogTemp, Warning, TEXT("Turret Dir : %f"), Dir)
	Dir = FMath::Clamp(Dir, -1, 1);
	float RotationnChange = Dir * MaximumRotationSpeed * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = GetRelativeRotation().Yaw + RotationnChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}
