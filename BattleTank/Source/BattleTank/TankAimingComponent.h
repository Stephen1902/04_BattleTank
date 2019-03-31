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
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Get location to aim turret and barrel at
	void AimAt(FVector HitLocation, float LaunchSpeed);

	//TODO Set Turret Reference
	UTankTurret* Turret = nullptr;
	void SetTurretReference(UTankTurret* TurretToSet);
	void MoveTurretTowards(FVector AimDirection);

	// Required for barrel movement
	UTankBarrel* Barrel = nullptr;
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void MoveBarrelTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Enum State")
	EFiringState FiringState = EFiringState::Reloading;

};
