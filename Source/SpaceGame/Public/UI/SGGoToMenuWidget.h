#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGGoToMenuWidget.generated.h"

class UButton;

UCLASS()
class SPACEGAME_API USGGoToMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UButton* GoToMenuButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnGoToMenu();
};
