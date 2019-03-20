// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * Variables and function(s) for rotating the turret
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	void RotateTurret(float RelativeSpeed);

	UPROPERTY(EditAnywhere, Category = "Set Up")
	float MaxDegreesPerSecond = 25; // Tested value
};
