#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SGSaveGame.generated.h"


UCLASS()
class SPACEGAME_API USGSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	int32 RecordMeteoriteDestroyed;
};
