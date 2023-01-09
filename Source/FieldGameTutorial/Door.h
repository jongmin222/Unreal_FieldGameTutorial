// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Door.generated.h"

UCLASS()
class FIELDGAMETUTORIAL_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere)
		float CloseTime;
	float DoorDeltaTime;
	bool bOpen;

	FTimerHandle DoorTimerHandle;

	FRotator OriginRotation;

	void Open();
	void Close();
};
