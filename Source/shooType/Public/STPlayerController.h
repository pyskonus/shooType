// Created by pyskonus for the shooType game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STPlayerController.generated.h"

/*class USTTextBox;*/

UCLASS()
class SHOOTYPE_API ASTPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
