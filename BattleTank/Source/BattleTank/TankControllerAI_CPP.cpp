// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankControllerAI_CPP.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankControllerAI_CPP::BeginPlay()
{
	Super::BeginPlay();

}

void ATankControllerAI_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	if (PlayerTank && AITank)
	{
		// TODO Move Towards Player
		
		// Aim Towards Player
		AITank->AimAt(PlayerTank->GetActorLocation());

		// Fire If Ready
		AITank->FireProjectile();
	}
}
