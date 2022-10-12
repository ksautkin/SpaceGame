#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SGCoreTypes.h"
#include "SGGameHUD.generated.h"


UCLASS()
class SPACEGAME_API ASGGameHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	// изменение состояния игры 
	void OnGameStateChanged(ESGGameState State);

protected:
	// hud игрока
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;
	// виджет паузы
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;
	// виджет конца игры
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;


	virtual void BeginPlay() override;

private:
	// контейнер всех виджетов 
	UPROPERTY()
	TMap<ESGGameState, UUserWidget*> GameWidgets;
	// текущий виджет 
	UPROPERTY()
	UUserWidget* CurrentGameWidget = nullptr;

};
