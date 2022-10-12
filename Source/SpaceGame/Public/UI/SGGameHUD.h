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
	// ��������� ��������� ���� 
	void OnGameStateChanged(ESGGameState State);

protected:
	// hud ������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;
	// ������ �����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;
	// ������ ����� ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;


	virtual void BeginPlay() override;

private:
	// ��������� ���� �������� 
	UPROPERTY()
	TMap<ESGGameState, UUserWidget*> GameWidgets;
	// ������� ������ 
	UPROPERTY()
	UUserWidget* CurrentGameWidget = nullptr;

};
