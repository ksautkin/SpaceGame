#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGMenuUserWidget.generated.h"

class UButton;
class USoundCue;

UCLASS()
class SPACEGAME_API USGMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* StartGameButton;
	UPROPERTY(meta = (BindWidget))
	UButton* QuitGameButton;
	// sound click
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* ClickSound;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnStartGame();
	UFUNCTION()
	void OnChangeLevel();

	UFUNCTION()
	void OnQuitGame();
	
};
