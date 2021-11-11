// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STBall.generated.h"

class UStaticMeshComponent;
class UWidgetComponent;

UCLASS()
class SHOOTYPE_API ASTBall : public AActor
{
	GENERATED_BODY()
	
public:
	ASTBall();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* BallMesh;
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void SetWord(const FString& Word);

	UPROPERTY()
	FString CurrentWord;
};
