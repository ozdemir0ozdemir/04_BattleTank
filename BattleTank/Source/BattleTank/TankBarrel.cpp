// Copyright Özdemir Özdemir 2023


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	float Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Tank Barrel Elevating : %f"), RelativeSpeed);



}
