// Created by pyskonus for the shooType game.


#include "STGameState.h"

void ASTGameState::OnTextChanged(const FText& Text)
{
	if (CurrentIndex == -1)
	{
		for (int i = 0; i < RemainingWords.Num(); ++i)
		{
			if (Text.ToString() == RemainingWords[i].Left(1))
			{
				CurrentIndex = i;
				OnWordChanged.Broadcast(RemainingWords[CurrentIndex]);
				RemainingWords[CurrentIndex] = RemainingWords[CurrentIndex].RightChop(1);	/// TODO: delegate to update STBall's text render component
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
				OnWordChanged.Broadcast(RemainingWords[CurrentIndex]);
				RemainingWords.RemoveAt(CurrentIndex);
				CurrentIndex = -1;
			} else
			{
				/// TODO: delegate to update STBall's text render component
				OnWordChanged.Broadcast(RemainingWords[CurrentIndex]);
				RemainingWords[CurrentIndex] = RemainingWords[CurrentIndex].RightChop(1);
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
