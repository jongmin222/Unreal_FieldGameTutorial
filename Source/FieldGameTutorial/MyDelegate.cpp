// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDelegate.h"

AMyDelegate::AMyDelegate()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor"));
}

void AMyDelegate::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));

	Fuc_DeleSingle.BindUFunction(this, FName("CallDeleFunc_Single"));
	Fuc_DeleSingle_OneParam.BindUFunction(this, FName("CallDeleFunc_Single_OneParam"));

	Fuc_DeleMulti.AddUFunction(this, FName("CallDeleFunc_Multi_1"));
	Fuc_DeleMulti.AddUFunction(this, FName("CallDeleFunc_Multi_2"));

	Fuc_DeleMulti_OneParam.AddUFunction(this, FName("CallDeleFunc_Single_OneParam_1"));
	Fuc_DeleMulti_OneParam.AddUFunction(this, FName("CallDeleFunc_Single_OneParam_2"));

	PrintInfo();
}

void AMyDelegate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyDelegate::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));

	//델리게이트 해제
	Fuc_DeleSingle.Unbind();
	Fuc_DeleSingle_OneParam.Unbind();

	Fuc_DeleMulti.Clear();
	Fuc_DeleMulti_OneParam.Clear();
}

//
void AMyDelegate::PostActorCreated()
{
	Super::PostActorCreated();
	UE_LOG(LogTemp, Warning, TEXT("PostActorCreated"));
}

//액터가 에디터에 생성 시 호출
void AMyDelegate::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

	UE_LOG(LogTemp, Warning, TEXT("OnConstruction"));
}

void AMyDelegate::PrintInfo()
{

	//델리게이트 바인딩 되어있는지 여부
	if (Fuc_DeleSingle.IsBound())
	{
		//델리게이트 호출
		Fuc_DeleSingle.Execute();
	}

	if (Fuc_DeleSingle_OneParam.IsBound())
	{
		Fuc_DeleSingle_OneParam.Execute(123);
	}


	if (Fuc_DeleMulti.IsBound())
	{
		Fuc_DeleMulti.Broadcast();
	}

	if (Fuc_DeleMulti_OneParam.IsBound())
	{
		Fuc_DeleMulti_OneParam.Broadcast(456);
	}
}

void AMyDelegate::CallDeleFunc_Single()
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Single"));
}

void AMyDelegate::CallDeleFunc_Single_OneParam(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Single_OneParam : %d"), nValue);
}

void AMyDelegate::CallDeleFunc_Multi_1()
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Multi_1"));
}

void AMyDelegate::CallDeleFunc_Multi_2()
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Multi_2"));
}

void AMyDelegate::CallDeleFunc_Single_OneParam_1(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Single_OneParam_1 : %d"), nValue);
}

void AMyDelegate::CallDeleFunc_Single_OneParam_2(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Single_OneParam_2 : %d"), nValue);
}
