// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Hold Paremeters for Barrel
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void ElevateBarrel(float DegreesPerSecond);

	UPROPERTY(EditAnywhere, Category = "Set Up")
	float MaxDegreesPerSecond = 20; // Sensible beginning value

	UPROPERTY(EditAnywhere, Category = "Set Up")
	float  ElevationMax = 30; // Sensible beginning value

	UPROPERTY(EditAnywhere, Category = "Set Up")
	float ElevationMin = 0; // Sensible beginning value


};

