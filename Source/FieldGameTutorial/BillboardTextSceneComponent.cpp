// Fill out your copyright notice in the Description page of Project Settings.


#include "BillboardTextSceneComponent.h"
#include "Components/TextRenderComponent.h"
#include "Camera/PlayerCameraManager.h"

// Sets default values for this component's properties
UBillboardTextSceneComponent::UBillboardTextSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Billboard Text"));
	Text->SetupAttachment(this);
	Text->SetHorizontalAlignment(EHTA_Center);
	Text->SetText(TEXT("Billboard"));

	Text->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	Text->SetWorldSize(150.0f);
}


// Called when the game starts
void UBillboardTextSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	camManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
}


// Called every frame
void UBillboardTextSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (camManager != nullptr)
	{
		Rotator = camManager->GetCameraRotation();
		Text->SetWorldRotation(FRotator(0, 180.0f+Rotator.Yaw, 0));
		UE_LOG(LogTemp, Log, TEXT("%f, %f, %f"), Rotator.Pitch, Rotator.Yaw, Rotator.Roll);
	}
}

