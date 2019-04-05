// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// ENUM for Aiming State
UENUM(BlueprintType)
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading
};

// Forward Declarations
class UTankBarrel; 
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Set Up")
	void InitialiseTurretBarrel(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Get location to aim turret and barrel at
	void AimAt(FVector HitLocation);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Enum State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	//Required for Turret Movement
	UTankTurret* Turret = nullptr;
	void MoveTurretTowards(FVector AimDirection);

	// Required for barrel movement
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 100000;  // TODO Find sensible default

};
