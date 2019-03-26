// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankControllerAI_CPP.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankMovementComponent.h"

void ATankControllerAI_CPP::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	AITank = Cast<ATank>(GetPawn());
}

void ATankControllerAI_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerTank && AITank)
	{
		// Move Towards Player
		MoveToActor(
			PlayerTank,
			AcceptanceRadius
		);
		
		// Aim Towards Player
		AITank->AimAt(PlayerTank->GetActorLocation());

		// Fire If Ready
		AITank->FireProjectile();
	}
}
