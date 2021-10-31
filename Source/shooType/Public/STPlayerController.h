// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STPlayerController.generated.h"


UCLASS()
class SHOOTYPE_API ASTPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class USTTextBox> TextBoxContainer;
	
	USTTextBox* TextBoxContainerInst;
	
	virtual void BeginPlay() override;

	/*UFUNCTION(BlueprintCallable)
	void Callback(const FText& Text);*/

protected:
	/*virtual void SetupInputComponent() override;

	void SignalInput();*/

	void OnTextChanged(const FText& Text);
};
