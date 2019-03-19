// Fill out your copyright notice in the Description page of Project Settings.

#include "TankControllerPlayerCPP.h"
#include "Engine/World.h"
#include "Tank.h"
// #include "BattleTank.h"

void ATankControllerPlayerCPP::BeginPlay()
{
	Super::BeginPlay();

	auto TankName = GetControlledTank();
	if (!TankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not possessed"));
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

// Get world location through linetrace on crosshair
	if (GetSightRayHitLocation(HitLocation))
	{
// If linetrace hits landscape
		GetControlledTank()->AimAt(HitLocation);
// Aim barrel to linetrace location


	}


}

bool ATankControllerPlayerCPP::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = { ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation };

	// Deproject the screen position of the crosshair to a world direction
	FVector WorldPosition, WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldPosition, WorldDirection))
	{
		// Line Trace along the look direction and see what we hit (up to a max range)
		if (GetLookVectorHitLocation(WorldDirection, OutHitLocation))
		{
			
		}


	}
	
	return true;
}

bool ATankControllerPlayerCPP::GetLookVectorHitLocation(FVector WorldDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (WorldDirection * LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	return false;  // Hasn't hit anything
	
}
