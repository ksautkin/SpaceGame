// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGCoreTypes.h"
#include "SpaceGameGameModeBase.generated.h"


UCLASS()
class SPACEGAME_API ASpaceGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	ESGGameState GameState = ESGGameState::WaitingToStart;

public:
	FOnGameStateChangedSignature OnGameStateChanged;

	ASpaceGameGameModeBase();
	// начало игры 
	virtual void StartPlay() override;
	// запуск паузы игры 
	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	// снятие паузы
	bool ClearPause() override;
	// изменение состояния игры 
	void SetGameState(ESGGameState State);
	// завершение игры 
	void GameOver();

private:
	void SaveRecord();
};
