// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#include "TankControllerAI_CPP.h"

void ATankControllerAI_CPP::BeginPlay()
{
	Super::BeginPlay();

	auto TankName = GetControlledTank();
	if (!TankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank possessed: %s"), *TankName->GetName());
	}
}

ATank* ATankControllerAI_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}