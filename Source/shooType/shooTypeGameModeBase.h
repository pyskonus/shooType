// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "shooTypeGameModeBase.generated.h"

class ASTBall;
class UNiagaraSystem;

USTRUCT()
struct FState
{
	GENERATED_BODY()

	int CurrentWave = 0;

	int WordsSpawned = 0;

	int WordsEntered = 0;

	int MainLength = 2;
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
	float WordPause = 2.5f;

	UPROPERTY(EditAnywhere, Category = "Location")
	float Radius = 9900.0f;

	UPROPERTY(EditAnywhere, Category = "Location")
	float SpawnZ = 420.0f;

	UPROPERTY(EditAnywhere, Category = "Classes")
	TSubclassOf<ASTBall> BallClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* Explosion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Blue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Green;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Purple;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Orange;

private:
	TMap<int, TArray<FString>> Words;

	FTimerHandle TimerHandle;

	FState State;

	TArray<ASTBall*> Ballz;

	UFUNCTION()
	void SpawnWord();

	UFUNCTION()
	void OnWordChanged(const FString& OldWord);

	void ChooseWord();
	void FindBallByWord(const FString& OldWord);

	UPROPERTY()
	ASTBall* CurrentBall = nullptr;
};
