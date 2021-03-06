// Fill out your copyright notice in the Description page of Project Settings.

#include "TankControllerPlayerCPP.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"
// #include "BattleTank.h"

void ATankControllerPlayerCPP::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent)
	{
		FoundAimingComponent(AimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming Component not found on Player Controller."));
	}

	auto TankName = GetPawn();
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

void ATankControllerPlayerCPP::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }

	FVector HitLocation = { 1.f, 0.f, 1.f };  // OUT Parameter

// Get world location through linetrace on crosshair
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation)
	{	
// If linetrace hits landscape
		AimingComponent->AimAt(HitLocation);
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
		return (GetLookVectorHitLocation(WorldDirection, OutHitLocation));
	}
	
	return false;
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
