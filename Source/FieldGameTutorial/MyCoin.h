// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCoin.generated.h"

UCLASS()
class FIELDGAMETUTORIAL_API AMyCoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCoin();

protected:
	// Called when the game starts or when spawned
	virtual void PostActorCreated() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void PreInitializeComponents() override;
	//virtual void InitializeComponent() override;
	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void BeginDestroy() override;
	virtual void FinishDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
