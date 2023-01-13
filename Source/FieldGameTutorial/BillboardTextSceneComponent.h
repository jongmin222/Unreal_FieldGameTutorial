// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BillboardTextSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIELDGAMETUTORIAL_API UBillboardTextSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBillboardTextSceneComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere)
	class APlayerCameraManager* camManager;

	UPROPERTY(EditAnywhere)
	FRotator Rotator;

	UPROPERTY(VisibleAnywhere)
	FVector Location;
};
