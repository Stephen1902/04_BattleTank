// Copyright 2019 DME Games - Written as part of the Udemy Unreal C++ Class

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Responsible for driving the tank tracks
 */

class UTankTrack;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Set Up")
	void InitialiseTracks(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throw); // Throw is level from -1 to 1 that the analogue control is being pressed

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnRight(float Throw); // Throw is level from -1 to 1 that the analogue control is being pressed


private:
	UTankTrack* LeftTrack;
	UTankTrack* RightTrack;

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};
