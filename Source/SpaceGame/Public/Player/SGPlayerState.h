#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SGPlayerState.generated.h"


UCLASS()
class SPACEGAME_API ASGPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	void AddMeteoriteDestroyed() { NumMeteoriteDestroyed++; }
	int32 GetNumberMeteoriteDestroyed() { return NumMeteoriteDestroyed; }

	void LogInfo();
	
private:
	int32 NumMeteoriteDestroyed = 0;
};
