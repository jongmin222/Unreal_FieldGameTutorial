// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelTransferVolum.h"
#include "Components/BoxComponent.h"
#include "CollidingPawn.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ALevelTransferVolum::ALevelTransferVolum()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TransferVolum = CreateDefaultSubobject<UBoxComponent>(TEXT("TransferVolum"));
	RootComponent = TransferVolum;
	TransferVolum->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
}

// Called when the game starts or when spawned
void ALevelTransferVolum::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALevelTransferVolum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALevelTransferVolum::NotifyActorBeginOverlap(AActor * OtherActor)
{
	ACollidingPawn* Pawn = Cast<ACollidingPawn>(OtherActor);
	if (Pawn != nullptr)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(*TransferLevelName));
	}
}