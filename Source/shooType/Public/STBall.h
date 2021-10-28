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
	static FVector GetForceDirection(const FVector& Original, const float CrossProductZ);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float BalancingForceModifier = 1000.f;
	
	FVector SpawnLocation;
	FVector VectorToCenter;
	FVector CurrentDirection;
	float Sin = 0;
	float Cos = 0;
	float Delta;

public:
	virtual void Tick(float DeltaTime) override;

};
