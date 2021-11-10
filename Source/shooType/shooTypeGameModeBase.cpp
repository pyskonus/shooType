// Created by pyskonus for the shooType game.


#include "shooTypeGameModeBase.h"

/*#include "STPlayerController.h"*/
#include "Engine.h"
#include "STBall.h"
#include "Core/Public/Misc/FileHelper.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"
#include "shooType/Public/STGameState.h"


AshooTypeGameModeBase::AshooTypeGameModeBase()
{
	/*PlayerControllerClass = ASTPlayerController::StaticClass();*/
	/*HUDClass = ASTHUD::StaticClass();
	GameStateClass = ASTGameState::StaticClass();*/

	for (int i = 2; i <= 14; i++)
	{
		Words.Add(i, TArray<FString>());
	}
}

void AshooTypeGameModeBase::StartPlay()
{
	Super::StartPlay();
	for (int i = 2; i <= 14; i++)
	{
		const FString Path = FPaths::ProjectContentDir() + "Data/" + FString::FromInt(i) + ".txt";	/*FPaths::ProjectContentDir() + */ /*shooType/Content/*/
		if (!FFileHelper::LoadANSITextFileToStrings(*Path, nullptr, Words[i]))
		{
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("FATAL ERROR: CANNOT LOAD WORDS"));
			return;
		}
	}

	ASTGameState* STGameState = GetWorld()->GetGameState<ASTGameState>();
	STGameState->OnWordChanged.AddUObject(this, &AshooTypeGameModeBase::OnWordChanged);
	
	/// TODO: what if file cannot be opened
}

void AshooTypeGameModeBase::StartWave()
{
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AshooTypeGameModeBase::SpawnWord, WavePause, false);

	
	State.WordsEntered = 0;
	State.WordsSpawned = 0;
	State.CurrentWave++;
	if (State.MainLength < 12)
		State.MainLength++;
}

void AshooTypeGameModeBase::SpawnWord()
{
	ChooseWord();
	
	/*UE_LOG(LogTemp, Warning, TEXT("Spawned word"));*/		/// TODO: Niagara effect
	if (State.WordsSpawned < 15)
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AshooTypeGameModeBase::SpawnWord, WordPause, false);
		
}

void AshooTypeGameModeBase::ChooseWord()
{
	if (!GetWorld())
		return;
	
	int Length = State.MainLength;
	if (State.WordsSpawned%5 % 2 == 1)
		State.WordsSpawned%5 == 1 ? Length-- : Length++;

	int InitialIndex = FMath::RandRange(0, Words[Length].Num());
	int Index = InitialIndex;
	
	ASTGameState* STGameState = GetWorld()->GetGameState<ASTGameState>();
	
	do
	{
		if (!STGameState->AddWord(Words[Length][Index]))
		{
			Index++;
			if(Index == Words[Length].Num())
				Index = 0;
		} else
		{
			UE_LOG(LogTemp, Display, TEXT("%s"), *Words[Length][Index]);

			/// spawn ball
			const float SpawnDirection = FMath::DegreesToRadians(FMath::RandRange(-45, 45));
			const float X = Radius * FMath::Cos(SpawnDirection);
			const float Y = Radius * FMath::Sin(SpawnDirection);
			const FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, FVector(X, Y, SpawnZ));
			ASTBall* NewBall = GetWorld()->SpawnActor<ASTBall>(BallClass, SpawnTransform);
			NewBall->CurrentWord = Words[Length][Index];
			NewBall->SetWord(Words[Length][Index]);
			Ballz.Add(NewBall);
			
			State.WordsSpawned++;
			break;
		}
	} while (Index != InitialIndex);
}

void AshooTypeGameModeBase::OnWordChanged(const FString& OldWord)
{
	if (CurrentBall == nullptr)
	{
		FindBallByWord(OldWord);
		CurrentBall->CurrentWord = OldWord.RightChop(1);
		CurrentBall->SetWord(OldWord.RightChop(1));
	} else
	{
		if (OldWord.Len() == 1)
		{
			Ballz.Remove(CurrentBall);
			CurrentBall->Destroy();
			CurrentBall = nullptr;
			State.WordsEntered++;
			if (State.WordsEntered == State.WordsSpawned && State.WordsEntered == 15)
				StartWave();
		} else
		{
			CurrentBall->CurrentWord = OldWord.RightChop(1);
			CurrentBall->SetWord(OldWord.RightChop(1));
		}
	}
}

void AshooTypeGameModeBase::FindBallByWord(const FString& OldWord)
{
	for (const auto Ball: Ballz)
	{
		if (Ball->CurrentWord == OldWord)
			CurrentBall = Ball;
	}
}