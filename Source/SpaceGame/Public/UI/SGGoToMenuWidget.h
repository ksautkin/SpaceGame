#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGGoToMenuWidget.generated.h"

class UButton;
class USoundCue;

UCLASS()
class SPACEGAME_API USGGoToMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UButton* GoToMenuButton;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* ClickSound;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnGoToMenu();
	UFUNCTION()
	void OnChangeLevel();
};
