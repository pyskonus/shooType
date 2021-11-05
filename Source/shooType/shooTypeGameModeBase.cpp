// Created by pyskonus for the shooType game.


#include "shooTypeGameModeBase.h"

#include <chrono>

#include "STGameState.h"
#include "STPlayerController.h"
#include "UI/STHUD.h"
#include "Engine.h"
#include "Core/Public/Misc/FileHelper.h"

#include <fstream>

AshooTypeGameModeBase::AshooTypeGameModeBase()
{
	PlayerControllerClass = ASTPlayerController::StaticClass();
	HUDClass = ASTHUD::StaticClass();
	GameStateClass = ASTGameState::StaticClass();

	for (int i = 2; i <= 15; i++)
	{
		Words.Add(i, TArray<FString>());
	}
}

void AshooTypeGameModeBase::StartPlay()
{
	for (int i = 2; i <= 15; i++)
	{
		const FString Path = FPaths::ProjectContentDir() + "/Data/" + FString::FromInt(i) + ".txt";
		FFileHelper::LoadANSITextFileToStrings(*Path, nullptr, Words[i]);
	}
	
	/// TODO: what if file cannot be opened

	int i = 0;
	for (const auto Word: Words[15])
	{
		if (i > 4)
			break;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Word);
		i++;
	}
}