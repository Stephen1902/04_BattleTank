// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::InitialiseTurretBarrel(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
	if (!ensure(TurretToSet && BarrelToSet)) { return; }

	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel && Turret)) { return; }

	FVector OutLaunchVelocity = { 0, 0, 0 };
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity
	bool bHasAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.f,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHasAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel)) { return; }
	// Work out difference between current barrel rotation and AimDirection rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAtRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAtRotator - BarrelRotator;

	Barrel->ElevateBarrel(DeltaRotator.Pitch);
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if (FiringState != EFiringState::OutOfAmmo)
	{
		if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
		{
			FiringState = EFiringState::Reloading;
		}
		else if (!IsBarrelMoving())
		{
			FiringState = EFiringState::Aiming;
		}
		else
		{
			FiringState = EFiringState::Locked;
		}
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	FVector CurrentBarrelRotation = Barrel->GetForwardVector();
	bool IsBarrelEqual = CurrentBarrelRotation.Equals(AimDirection, 0.01f);
	return IsBarrelEqual;
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	if (!ensure(Turret)) { return; }

	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAtRotator = AimDirection.Rotation();
	FRotator DeltaRotator = (AimAtRotator - TurretRotator);

	// Always rotate the shortest way to target
	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		Turret->RotateTurret(DeltaRotator.Yaw);
	}
	else
	{
		Turret->RotateTurret(-DeltaRotator.Yaw);
	}
}

void UTankAimingComponent::FireProjectile()
{
	if (FiringState == EFiringState::OutOfAmmo || ProjectileBluePrint == NULL) { return; }

	if (FiringState != EFiringState::Reloading)
	{
		auto SocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto SocketRotation = Barrel->GetSocketRotation(FName("Projectile"));
		// Spawn a projectile at the socket location of the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBluePrint,
			SocketLocation,
			SocketRotation
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		NumberOfAmmo--;
		if (NumberOfAmmo == 0)
		{
			FiringState = EFiringState::OutOfAmmo;
		}
	}

}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

int UTankAimingComponent::GetAmmoRemaining() const
{
	return NumberOfAmmo;
}