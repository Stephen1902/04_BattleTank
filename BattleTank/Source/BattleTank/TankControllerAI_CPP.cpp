// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankControllerAI_CPP.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankMovementComponent.h"
#include "TankAimingComponent.h"

void ATankControllerAI_CPP::BeginPlay()
{
	Super::BeginPlay();

	
}

void ATankControllerAI_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	if (PlayerTank && AITank)
	{
		auto TankAimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();

		// Move Towards Player
		MoveToActor(
			PlayerTank,
			AcceptanceRadius
		);

		// Aim Towards Player
		TankAimingComponent->AimAt(PlayerTank->GetActorLocation());

		// Fire If Ready
		// AITank->FireProjectile();
	}
	
}
