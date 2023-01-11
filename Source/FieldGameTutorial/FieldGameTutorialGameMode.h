// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FieldGameTutorialGameMode.generated.h"

UCLASS(minimalapi)
class AFieldGameTutorialGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFieldGameTutorialGameMode();

	UFUNCTION(BlueprintCallable, Category = "UMG_Game")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;
};



