// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankControllerPlayerCPP.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankControllerPlayerCPP : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector WorldDirection, FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly, Category = "Crosshair Location")
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category = "Crosshair Location")
	float CrosshairYLocation = 0.333333f;

	UPROPERTY(EditDefaultsOnly, Category = "Range Of LineTrace")
	float LineTraceRange = 1000000.f;
};
