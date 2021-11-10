// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "STGameState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnWordChanged, const FString&);

UCLASS()
class SHOOTYPE_API ASTGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void OnTextChanged(const FText& Text);

	bool AddWord(FString Word);

	FOnWordChanged OnWordChanged;

private:
	TArray<FString> RemainingWords;

	int CurrentIndex = -1;	/// -1 means no word is currently being typed
};
