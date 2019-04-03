// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankControllerPlayerCPP.generated.h"

// Forward Declarations
class ATank;
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankControllerPlayerCPP : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Set up")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Set up")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
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
