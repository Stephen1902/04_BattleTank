// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankControllerAI_CPP.generated.h"

// Forward Declarations
class ATank;
class UTankMovementComponent;
class UTankAimingComponent;

/**
 A Controller for the AI thanks created or spawned into the world
 */
UCLASS()
class BATTLETANK_API ATankControllerAI_CPP : public AAIController
{
	GENERATED_BODY()

// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void BeginPlay() override;

	// UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Set up")
	float AcceptanceRadius = 3000.f;  // TODO Find Acceptable Radius to stop movement
};
