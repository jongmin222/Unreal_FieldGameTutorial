// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "CollidingPawnMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FIELDGAMETUTORIAL_API UCollidingPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
private:
	float MoveSpeed = 0.0f;
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
