// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
// Given a max elevation speed and the frame time
	float ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevateChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevateChange;

	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}