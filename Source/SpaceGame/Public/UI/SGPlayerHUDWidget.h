#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGPlayerHUDWidget.generated.h"


UCLASS()
class SPACEGAME_API USGPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetAmountShotsPercent() const;
	
};
