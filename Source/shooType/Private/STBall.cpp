// Fill out your copyright notice in the Description page of Project Settings.


#include "STBall.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

ASTBall::ASTBall()
{
	PrimaryActorTick.bCanEverTick = true;
	
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	SetRootComponent(BallMesh);
	BallMesh->SetSimulatePhysics(true);
}

void ASTBall::BeginPlay()
{
	Super::BeginPlay();

	SpawnLocation = GetActorLocation();
	VectorToCenter = FVector::ZeroVector - SpawnLocation;
	VectorToCenter.Z = 0;
}

void ASTBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentDirection = GetActorLocation() - SpawnLocation;
	CurrentDirection.Z = 0;
	Cos = FVector::DotProduct(VectorToCenter, CurrentDirection) / VectorToCenter.Size() / CurrentDirection.Size();
	Sin = std::sqrt(1 - Cos * Cos);

	
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Yellow, *FString::SanitizeFloat(Sin));
}

