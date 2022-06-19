#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGGameOverWidget.generated.h"

class UButton;

UCLASS()
class SPACEGAME_API USGGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* ResetLevelButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnResetLevel();
};
