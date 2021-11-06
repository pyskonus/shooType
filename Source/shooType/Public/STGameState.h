// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "STGameState.generated.h"

UCLASS()
class SHOOTYPE_API ASTGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void OnTextChanged(const FText& Text);

	bool AddWord(FString Word);

private:
	TArray<FString> RemainingWords;
};
