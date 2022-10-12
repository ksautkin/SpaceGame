#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGGameOverWidget.generated.h"

class UButton;
class USoundCue;

UCLASS()
class SPACEGAME_API USGGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* ResetLevelButton;
	// sound click
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* ClickSound;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnResetLevel();
	UFUNCTION()
	void OnChangeLevel();
};
