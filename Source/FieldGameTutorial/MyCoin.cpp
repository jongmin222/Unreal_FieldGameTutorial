// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCoin.h"

AMyCoin::AMyCoin()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor"));
}

//������ ȣ�� ���� ȣ��
void AMyCoin::PostActorCreated()
{
	Super::PostActorCreated();
	UE_LOG(LogTemp, Warning, TEXT("PostActorCreated"));
}

//���� ����
void AMyCoin::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
	UE_LOG(LogTemp, Warning, TEXT("OnConstruction"));
}

//������Ʈ �ʱ�ȭ ����
void AMyCoin::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("PreInitializeComponents"));
}

//������Ʈ �ʱ�ȭ ����
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

//Destroy�� ù��° ȣ��, �����÷��� ���� ó�� �ϱ�
void AMyCoin::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));	
}

//������Ʈ �޸� ���� �ϱ�
void AMyCoin::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(LogTemp, Warning, TEXT("BeginDestroy"));
}

//�޸� ���� �� ������ ȣ��
void AMyCoin::FinishDestroy()
{
	Super::FinishDestroy();
	UE_LOG(LogTemp, Warning, TEXT("FinishDestroy"));
}

void AMyCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
