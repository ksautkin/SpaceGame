#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SGGameHUD.generated.h"


UCLASS()
class SPACEGAME_API ASGGameHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	// hud игрока
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

	virtual void BeginPlay() override;
};
