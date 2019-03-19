// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankControllerAI_CPP.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankControllerAI_CPP : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void BeginPlay() override;
};
