// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STHUD.generated.h"

class USTTextBox;

UCLASS()
class SHOOTYPE_API ASTHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<USTTextBox> TextBoxContainer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	USTTextBox* TextBoxContainerInst;
};
