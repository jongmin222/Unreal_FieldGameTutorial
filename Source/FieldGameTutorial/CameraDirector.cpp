// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeToNextCameraChange -= DeltaTime;
	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		// 로컬 플레이어의 컨트롤을 처리하는 액터를 찾습니다.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{			
			for (int i = 0; i < Cameras.Num(); ++i)
			{
				if ((OurPlayerController->GetViewTarget() == Cameras[i]))
				{
					// 1 번 카메라로 즉시 컷해 들어갑니다.
					if (i + 1 < Cameras.Num())
					{
						if (Cameras[i + 1] != nullptr)
						{
							OurPlayerController->SetViewTargetWithBlend(Cameras[i + 1], SmoothBlendTime);
							UE_LOG(LogTemp, Log, TEXT("%d"),i);
							break;
						}
					}
					else if (Cameras[0] != nullptr)
					{
						OurPlayerController->SetViewTargetWithBlend(Cameras[0], SmoothBlendTime);
						UE_LOG(LogTemp, Log, TEXT("%d"),i);
						break;
					}
				}
			}
		}
	}
}

