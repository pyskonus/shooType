// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "shooTypeGameModeBase.generated.h"

USTRUCT()
struct FState
{
	GENERATED_BODY()

	int CurrentWave = 0;

	int WordsSpawned = 0;

	int WordsEntered = 0;

	int MainLength = 3;
};

UCLASS()
class SHOOTYPE_API AshooTypeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AshooTypeGameModeBase();

	void StartWave();

protected:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, Category = "Time")
	float WavePause = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Time")
	float WordPause = 1.5f;

private:
	TMap<int, TArray<FString>> Words;

	FTimerHandle TimerHandle;

	FState State;

	UFUNCTION()
	void SpawnWord();

	void ChooseWord();
};
