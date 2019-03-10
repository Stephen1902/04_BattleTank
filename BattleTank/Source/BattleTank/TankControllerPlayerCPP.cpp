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

void ATankControllerPlayerCPP::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank* ATankControllerPlayerCPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankControllerPlayerCPP::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation = { 1.f, 0.f, 1.f };  // OUT Parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}

	// Get world location through linetrace on crosshair

	// If linetrace hits landscape

	// Aim barrel to linetrace location
}

bool ATankControllerPlayerCPP::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	UE_LOG(LogTemp, Warning, TEXT("OutHitLocation: %s"), *OutHitLocation.ToString());
	OutHitLocation = { 2.f, 2.f, 4.f };

	return true;
}
