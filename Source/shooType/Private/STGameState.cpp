// Created by pyskonus for the shooType game.


#include "STGameState.h"

void ASTGameState::OnTextChanged(const FText& Text)
{
	/*UE_LOG(LogTemp, Display, TEXT("%s"), *Text.ToString());*/

	if (CurrentIndex == -1)
	{
		for (int i = 0; i < RemainingWords.Num(); ++i)
		{
			if (Text.ToString() == RemainingWords[i].Left(1))
			{
				CurrentIndex = i;
				RemainingWords[CurrentIndex] = RemainingWords[CurrentIndex].RightChop(1);	/// TODO: delegate to update STBall's text render component
				UE_LOG(LogTemp, Warning, TEXT("%s"), *RemainingWords[CurrentIndex]);
				return;
			}
		}
		/// TODO: mistake, play the sound
	} else
	{
		if (Text.ToString() == RemainingWords[CurrentIndex].Left(1))
		{
			if (RemainingWords[CurrentIndex].Len() == 1)
			{
				/// TODO: delegate to destroy STBall
				UE_LOG(LogTemp, Error, TEXT("%s"), *RemainingWords[CurrentIndex]);
				RemainingWords.RemoveAt(CurrentIndex);
				CurrentIndex = -1;
			} else
			{
				/// TODO: delegate to update STBall's text render component
				RemainingWords[CurrentIndex] = RemainingWords[CurrentIndex].RightChop(1);
				UE_LOG(LogTemp, Warning, TEXT("%s"), *RemainingWords[CurrentIndex]);
			}
		} else
		{
			/// TODO: mistake, play the sound
		}
	}
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

/*void ASTGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	for (const auto& Word: RemainingWords)
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *Word));
}*/
