// Created by pyskonus for the shooType game.


#include "STPlayerController.h"
#include "Blueprint/UserWidget.h"

/*void ASTPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!InputComponent) return;
	InputComponent->BindAction("KeyPressed", IE_Pressed, this, &ASTPlayerController::SignalInput);
}

void ASTPlayerController::SignalInput()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("KeyPressed"), true, FVector2D(2,2));
}*/

/*void ASTPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (TextBoxContainer)
	{
		TextBoxContainerInst = CreateWidget<USTTextBox>(this, TextBoxContainer);
		
		if (TextBoxContainerInst)
		{
			
			/*TextBoxContainerInst->OnTextChanged.BindLambda([](const FText& Text){UE_LOG(LogTemp, Warning, TEXT("Mmm mmm yeah yeah"))});#1#
			TextBoxContainerInst->AddToViewport();
			TextBoxContainerInst->MyOnTextChanged.AddUObject(this, &ASTPlayerController::OnTextChanged);
			/*TextBoxContainerInst->OnTextChanged.BindUObject(this, &ASTPlayerController::OnTextChanged);#1#
		}

		/*SetInputMode(this, TextBoxContainerInst.)#1#
		
		bShowMouseCursor = true;
	}
}*/

void ASTPlayerController::OnTextChanged(const FText& Text)
{
	UE_LOG(LogTemp, Display, TEXT("%s"), *Text.ToString());
}