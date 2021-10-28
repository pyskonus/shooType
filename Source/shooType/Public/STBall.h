// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STBall.generated.h"

class UStaticMeshComponent;

UCLASS()
class SHOOTYPE_API ASTBall : public AActor
{
	GENERATED_BODY()
	
public:
	ASTBall();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* BallMesh;
	
	FVector SpawnLocation;
	FVector VectorToCenter;
	FVector CurrentDirection;
	float Sin = 0;
	float Cos = 0;

public:
	virtual void Tick(float DeltaTime) override;

};
