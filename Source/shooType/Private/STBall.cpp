// Created by pyskonus for the shooType game.


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
}

void ASTBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


