#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SGGameInstance.generated.h"

UCLASS()
class SPACEGAME_API USGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	FName GetStartupLevelName() const { return StartupLevelName; }
	FName GetMenuLevelName() const { return MenuLevelName; }
	void SetRecordMeteoriteDestroyed(int32 Record) { RecordMeteoriteDestroyed = Record; }
	int32 GetRecordMeteoriteDestroyed() { return RecordMeteoriteDestroyed; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName StartupLevelName = NAME_None;
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName MenuLevelName = NAME_None;
	int32 RecordMeteoriteDestroyed = 0;
};
