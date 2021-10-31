// Created by pyskonus for the shooType game.


#include "UI/STHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Public/STTextBox.h"
#include "STPlayerController.h"

void ASTHUD::BeginPlay()
{
	Super::BeginPlay();

	if (TextBoxContainer)
	{
		const auto STPlayerController = Cast<ASTPlayerController>(GetOwningPlayerController());
		
		TextBoxContainerInst = CreateWidget<USTTextBox>(STPlayerController, TextBoxContainer);
		
		if (TextBoxContainerInst)
		{
			
			/*TextBoxContainerInst->OnTextChanged.BindLambda([](const FText& Text){UE_LOG(LogTemp, Warning, TEXT("Mmm mmm yeah yeah"))});*/
			/*TextBoxContainerInst->OnTextChanged.BindUObject(this, &ASTPlayerController::OnTextChanged);*/
			
			TextBoxContainerInst->AddToViewport();
			TextBoxContainerInst->MyOnTextChanged.AddUObject(STPlayerController, &ASTPlayerController::OnTextChanged);
		}

		/*SetInputMode(this, TextBoxContainerInst.)*/
	}
}
