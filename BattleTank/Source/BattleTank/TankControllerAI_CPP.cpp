// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankControllerAI_CPP.h"
#include "Engine/World.h"

void ATankControllerAI_CPP::BeginPlay()
{
	Super::BeginPlay();

	auto TankName = GetControlledTank();
	if (!TankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank possessed: %s"), *TankName->GetName());
	}
}

void ATankControllerAI_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move Towards Player
		
		// Aim Towards Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire If Ready
	}
}

ATank * ATankControllerAI_CPP::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}



ATank* ATankControllerAI_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}