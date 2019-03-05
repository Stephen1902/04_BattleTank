// Fill out your copyright notice in the Description page of Project Settings.

// #include "BattleTank.h"
#include "TankControllerPlayerCPP.h"

void ATankControllerPlayerCPP::BeginPlay()
{
	Super::BeginPlay();

	auto TankName = GetControlledTank();
	if (!TankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank possessed: %s"), *TankName->GetName());
	}
}

ATank* ATankControllerPlayerCPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}