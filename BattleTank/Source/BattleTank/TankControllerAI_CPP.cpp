// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankControllerAI_CPP.h"
#include "Engine/World.h"


ATank * ATankControllerAI_CPP::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankControllerAI_CPP::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank name: %s"), *PlayerTank->GetName());
	}

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

ATank* ATankControllerAI_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}