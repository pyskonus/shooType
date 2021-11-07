// Created by pyskonus for the shooType game.


#include "STGameState.h"

void ASTGameState::OnTextChanged(const FText& Text)
{
	UE_LOG(LogTemp, Display, TEXT("%s"), *Text.ToString());
}

bool ASTGameState::AddWord(FString Word)
{
	for (const auto Element: RemainingWords)
	{
		if (Word.Left(1) == Element.Left(1))
		{
			return false;
		}
	}
	RemainingWords.Add(Word);
	return true;
}

void ASTGameState::Tick(float DeltaSeconds)
{
	for (const auto& Word: RemainingWords)
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *Word));
}
