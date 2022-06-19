#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SGMenuHUD.generated.h"

UCLASS()
class SPACEGAME_API ASGMenuHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> MenuWidgetClass;

	virtual void BeginPlay() override;
};
