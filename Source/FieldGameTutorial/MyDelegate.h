// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDelegate.generated.h"

//��������Ʈ�� �ڷ��� �̸� �տ� ������ ��
// �̱�ĳ��Ʈ
DECLARE_DELEGATE(FDele_Single);
DECLARE_DELEGATE_OneParam(FDele_Single_OneParam, int32);

//��Ƽĳ��Ʈ
DECLARE_MULTICAST_DELEGATE(FDele_Multi);
DECLARE_MULTICAST_DELEGATE_OneParam(FDele_Multi_OneParam, int32);

//���̳���
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDele_Dynamic);
//DECLARE_DYNAMIC_DELEGATE(FDele_Dynamic);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_Dynamic_OneParam, int32);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_Dynamic_OneParam, int32, SomeParameter);

UCLASS()
class FIELDGAMETUTORIAL_API AMyDelegate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDelegate();

	FDele_Single Fuc_DeleSingle;
	FDele_Single_OneParam Fuc_DeleSingle_OneParam;

	FDele_Multi Fuc_DeleMulti;
	FDele_Multi_OneParam Fuc_DeleMulti_OneParam;

	//FDele_Dynamic Fuc_DeleDynamic;
	//FDele_Dynamic_OneParam Fuc_DeleDynamic_OneParam;
	
	void PrintInfo();

	UFUNCTION()
		void CallDeleFunc_Single();
	UFUNCTION()
		void CallDeleFunc_Single_OneParam(int32 nValue);

	UFUNCTION()
		void CallDeleFunc_Multi_1();
	UFUNCTION()
		void CallDeleFunc_Multi_2();
	UFUNCTION()
		void CallDeleFunc_Single_OneParam_1(int32 nValue);
	UFUNCTION()
		void CallDeleFunc_Single_OneParam_2(int32 nValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
