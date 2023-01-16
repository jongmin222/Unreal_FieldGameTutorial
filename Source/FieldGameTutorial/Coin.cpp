// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "ConstructorHelpers.h"
#include "CollidingPawn.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
	if (MeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	//Mesh->bGenerateOverlapEvents = true;
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoin::NotifyActorBeginOverlap(AActor * OtherActor)
{
	ACollidingPawn* Pawn = Cast<ACollidingPawn>(OtherActor);
	if (Pawn != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("overlap !!"));

	}
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

