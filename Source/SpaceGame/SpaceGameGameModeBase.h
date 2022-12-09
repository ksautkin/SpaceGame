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
	// ������ ���� 
	virtual void StartPlay() override;
	// ������ ����� ���� 
	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	// ������ �����
	bool ClearPause() override;
	// ��������� ��������� ���� 
	void SetGameState(ESGGameState State);
	// ���������� ���� 
	void GameOver();

private:
	void SaveRecord();
};
