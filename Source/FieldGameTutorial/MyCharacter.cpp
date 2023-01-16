// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyCoin.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::NotifyActorBeginOverlap(AActor * OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("¿‘¿Â !!"));
	AMyCoin* Coin = Cast<AMyCoin>(OtherActor);
	if (Coin != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("overlap !!"));
		//FVector Vector = Coin->GetActorWorldLocation();
		//Coin->SetActorWorldLocation
	}
}