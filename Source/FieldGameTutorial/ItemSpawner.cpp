// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSpawner.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Coin.h"
// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

}

// Called when the game starts or when spawned
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnRotation = GetActorRotation();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, 5.0f, true);
}

// Called every frame
void AItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemSpawner::SpawnItem()
{
	SpawnLocation = GetActorLocation();
	SpawnLocation.X += FMath::RandRange(500.0f, -500.0f);
	SpawnLocation.Y += FMath::RandRange(500.0f, -500.0f);

	GetWorld()->SpawnActor<ACoin>(SpawnLocation, SpawnRotation);
}

