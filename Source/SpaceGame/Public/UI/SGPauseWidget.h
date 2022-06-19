#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGPauseWidget.generated.h"

class UButton;

UCLASS()
class SPACEGAME_API USGPauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* ClearPauseButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnClearPause();
};
