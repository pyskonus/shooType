// Created by pyskonus for the shooType game.


#include "shooTypeGameModeBase.h"

#include <chrono>

#include "STPlayerController.h"
#include "Engine.h"
#include "Core/Public/Misc/FileHelper.h"

AshooTypeGameModeBase::AshooTypeGameModeBase()
{
	/*PlayerControllerClass = ASTPlayerController::StaticClass();*/
	/*HUDClass = ASTHUD::StaticClass();
	GameStateClass = ASTGameState::StaticClass();*/

	for (int i = 2; i <= 15; i++)
	{
		Words.Add(i, TArray<FString>());
	}
}

void AshooTypeGameModeBase::StartPlay()
{
	Super::StartPlay();
	for (int i = 2; i <= 15; i++)
	{
		const FString Path = "shooType/Content/Data/" + FString::FromInt(i) + ".txt";	/*FPaths::ProjectContentDir() + */
		if (!FFileHelper::LoadANSITextFileToStrings(*Path, nullptr, Words[i]))
		{
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("FATAL ERROR: CANNOT LOAD WORDS"));
			
			/*FLatentActionInfo LatentActionInfo;
			LatentActionInfo.CallbackTarget = this;
			LatentActionInfo.ExecutionFunction = "TestCall";
			LatentActionInfo.UUID = 123;
			LatentActionInfo.Linkage = 0;
			UKismetSystemLibrary::Delay(this, 5.0f, LatentActionInfo);*/
			
			/*UKismetSystemLibrary::QuitGame(this, UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, true);*/	/// TODO:: uncomment
		}
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