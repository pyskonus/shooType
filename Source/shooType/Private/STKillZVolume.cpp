// Fill out your copyright notice in the Description page of Project Settings.


#include "STKillZVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
ASTKillZVolume::ASTKillZVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(1000, 1000, 5));

}

// Called when the game starts or when spawned
void ASTKillZVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTKillZVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASTKillZVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	/*UEngine::AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Destroyed %s"), *OtherActor->StaticClass()->GetFName().ToString());*/
	UE_LOG(LogTemp, Warning, TEXT("Destroyed %s"), *OtherActor->StaticClass()->GetFName().ToString());
	OtherActor->Destroy();
}

