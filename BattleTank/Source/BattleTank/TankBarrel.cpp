// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed and the frame time
	float ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevateChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevateChange;

	SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation, ElevationMin, ElevationMax), 0, 0));


}