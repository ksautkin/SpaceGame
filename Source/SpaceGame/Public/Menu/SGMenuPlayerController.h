#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SGMenuPlayerController.generated.h"

UCLASS()
class SPACEGAME_API ASGMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
};
