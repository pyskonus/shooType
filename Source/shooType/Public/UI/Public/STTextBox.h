// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STTextBox.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FMyOnTextChanged, const FText&);
DECLARE_MULTICAST_DELEGATE(FOnFocus);

UCLASS()
class SHOOTYPE_API USTTextBox : public UUserWidget
{
	GENERATED_BODY()

public:
	FMyOnTextChanged MyOnTextChanged;
	FOnFocus OnFocusDelegate;
	
protected:
	UFUNCTION(BlueprintCallable)
	void OnTextChanged(const FText& Text);

	UFUNCTION(BlueprintCallable)
	void OnFocus();
	
};
