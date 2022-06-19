#include "SpaceGameGameModeBase.h"
#include "GameFramework/GameMode.h"
#include "Player/SGBaseCharacter.h"
#include "Player/SGPlayerController.h"
#include "Enemies/SGSpawnEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/GameMode.h"


ASpaceGameGameModeBase::ASpaceGameGameModeBase()
{
	// установка классов GameMode по умолчанию 
	DefaultPawnClass = ASGBaseCharacter::StaticClass();
	PlayerControllerClass = ASGPlayerController::StaticClass();
}

void ASpaceGameGameModeBase::StartPlay()
{
	Super::StartPlay();
	SetGameState(ESGGameState::InProgress);
}

bool ASpaceGameGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
	const bool PauseSet = Super::SetPause(PC, CanUnpauseDelegate);

	if (PauseSet)
	{
		SetGameState(ESGGameState::Pause);
	}

	return PauseSet;
}

bool ASpaceGameGameModeBase::ClearPause()
{
	const auto PauseCleared = Super::ClearPause();
	if (PauseCleared)
	{
		SetGameState(ESGGameState::InProgress);
	}
	return PauseCleared;
}

void ASpaceGameGameModeBase::SetGameState(ESGGameState State)
{
	if (GameState == State)
		return;

	GameState = State;
	OnGameStateChanged.Broadcast(GameState);
}

void ASpaceGameGameModeBase::GameOver()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASGSpawnEnemy::StaticClass(), FoundActors);
	// остановка всех спаунов 
	for (auto FoundActor : FoundActors)
	{
		ASGSpawnEnemy* SpawnEnemy = Cast<ASGSpawnEnemy>(FoundActor);
		if (SpawnEnemy)
			SpawnEnemy->StopSpawnEnemy();
	}
	SetGameState(ESGGameState::GameOver);
}
