// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Variables and functions for elevating and lowering of barrel
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement, +1 is max up movement
	void ElevateBarrel(float RelativeSpeed);

	UPROPERTY(EditDefaultsOnly, Category = "Set Up")
	float MaxDegreesPerSecond = 10; // Tested value

	UPROPERTY(EditDefaultsOnly, Category = "Set Up")
	float  ElevationMax = 40; // Sensible beginning value

	UPROPERTY(EditDefaultsOnly, Category = "Set Up")
	float ElevationMin = 0; // Sensible beginning value


};

