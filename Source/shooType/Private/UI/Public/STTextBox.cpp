// Created by pyskonus for the shooType game.


#include "UI/Public/STTextBox.h"

void USTTextBox::OnTextChanged(const FText& Text)
{
	UE_LOG(LogTemp, Warning, TEXT("It works"));
	MyOnTextChanged.Broadcast(Text);
}