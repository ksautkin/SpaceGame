#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGPauseWidget.generated.h"

class UButton;
class USoundCue;

UCLASS()
class SPACEGAME_API USGPauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* ClearPauseButton;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* ClickSound;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnClearPause();
};
