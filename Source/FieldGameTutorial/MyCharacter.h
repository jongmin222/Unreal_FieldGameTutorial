// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class FIELDGAMETUTORIAL_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();


public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite)
		float Health;
	UPROPERTY(BlueprintReadWrite)
		float Energy;
	UPROPERTY(BlueprintReadWrite)
		float Ammo;
	UPROPERTY(BlueprintReadWrite)
		float MaxAmmo;


	UPROPERTY(EditAnywhere)
		class UUserWidget* Widget;

};
