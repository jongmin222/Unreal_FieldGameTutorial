// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCoin.h"

AMyCoin::AMyCoin()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor"));
}

//생성자 호출 직후 호출
void AMyCoin::PostActorCreated()
{
	Super::PostActorCreated();
	UE_LOG(LogTemp, Warning, TEXT("PostActorCreated"));
}

//액터 생성
void AMyCoin::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
	UE_LOG(LogTemp, Warning, TEXT("OnConstruction"));
}

//컴포넌트 초기화 이전
void AMyCoin::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("PreInitializeComponents"));
}

//컴포넌트 초기화 이후
void AMyCoin::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("PostInitializeComponents"));
}

void AMyCoin::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
}

//Destroy시 첫번째 호출, 게임플레이 관련 처리 하기
void AMyCoin::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));	
}

//오브젝트 메모리 해제 하기
void AMyCoin::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(LogTemp, Warning, TEXT("BeginDestroy"));
}

//메모리 해제 전 마지막 호출
void AMyCoin::FinishDestroy()
{
	Super::FinishDestroy();
	UE_LOG(LogTemp, Warning, TEXT("FinishDestroy"));
}

void AMyCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
