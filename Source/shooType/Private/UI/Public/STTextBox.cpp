// Created by pyskonus for the shooType game.


#include "UI/Public/STTextBox.h"

void USTTextBox::OnTextChanged(const FText& Text)
{
	if (!Text.IsEmpty())
		MyOnTextChanged.Broadcast(Text);
}

void USTTextBox::OnFocus()
{
}