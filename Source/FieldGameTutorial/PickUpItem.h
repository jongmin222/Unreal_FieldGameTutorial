// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PickUpItem.generated.h"


UCLASS()
class FIELDGAMETUTORIAL_API UPickUpItem : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickUpItem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame

		
};
