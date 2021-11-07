// Created by pyskonus for the shooType game.


#include "UI/STHUD.h"

#include "STGameState.h"
#include "Blueprint/UserWidget.h"
#include "UI/Public/STTextBox.h"
#include "STPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "shooType/shooTypeGameModeBase.h"

void ASTHUD::BeginPlay()
{
	Super::BeginPlay();
	/*FString A = "matafaka";
	UE_LOG(LogTemp, Warning, TEXT("%s"), *A.RightChop(1));*/
	if (TextBoxContainer)
	{
		const auto STPlayerController = Cast<ASTPlayerController>(GetOwningPlayerController());
		
		TextBoxContainerInst = CreateWidget<USTTextBox>(STPlayerController, TextBoxContainer);
		
		if (TextBoxContainerInst)
		{
			/*TextBoxContainerInst->OnTextChanged.BindLambda([](const FText& Text){UE_LOG(LogTemp, Warning, TEXT("Mmm mmm yeah yeah"))});*/
			/*TextBoxContainerInst->OnTextChanged.BindUObject(this, &ASTPlayerController::OnTextChanged);*/
			
			TextBoxContainerInst->AddToViewport();
			if (GetWorld())
			{
				ASTGameState* STGameState = GetWorld()->GetGameState<ASTGameState>();
				TextBoxContainerInst->MyOnTextChanged.AddUObject(STGameState, &ASTGameState::OnTextChanged);
				AshooTypeGameModeBase* STGameMode = Cast<AshooTypeGameModeBase>(GetWorld()->GetAuthGameMode());
				TextBoxContainerInst->OnFocusDelegate.AddUObject(STGameMode, &AshooTypeGameModeBase::StartWave);
			}
		}
	}
}
