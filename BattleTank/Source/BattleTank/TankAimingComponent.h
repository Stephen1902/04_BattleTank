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
	Reloading,
	OutOfAmmo
};

// Forward Declarations
class UTankBarrel; 
class UTankTurret;
class AProjectile;

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

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void FireProjectile();

	EFiringState GetFiringState() const;

	UPROPERTY(BlueprintReadOnly, Category = "Fire")
	int32 NumberOfAmmo = 3;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Enum State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();

	//Required for Turret Movement
	UTankTurret* Turret = nullptr;
	void MoveTurretTowards(FVector AimDirection);

	// Required for barrel movement
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;  // TODO Find sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	double LastFireTime = 0;

	FVector AimDirection;
};
