#include "SpaceGameGameModeBase.h"
#include "GameFramework/GameMode.h"
#include "Player/SGBaseCharacter.h"
#include "Player/SGPlayerController.h"
#include "Enemies/SGSpawnEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/GameMode.h"
#include "SGSaveGame.h"
#include "Player/SGPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "SGGameInstance.h"


ASpaceGameGameModeBase::ASpaceGameGameModeBase()
{
	// установка классов GameMode по умолчанию 
	DefaultPawnClass = ASGBaseCharacter::StaticClass();
	PlayerControllerClass = ASGPlayerController::StaticClass();
}

void ASpaceGameGameModeBase::StartPlay()
{
	Super::StartPlay();

	// load record meteorite destroyed
	{
		const auto GameInstance = GetWorld()->GetGameInstance<USGGameInstance>();
		if (GameInstance)
		{
			USGSaveGame* SaveGameObject = Cast<USGSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveRecord"), 0));
			if (SaveGameObject)
			{
				GameInstance->SetRecordMeteoriteDestroyed(SaveGameObject->RecordMeteoriteDestroyed);
			}
			else
			{
				SaveGameObject = Cast<USGSaveGame>(UGameplayStatics::CreateSaveGameObject(USGSaveGame::StaticClass()));
				UGameplayStatics::SaveGameToSlot(SaveGameObject, TEXT("SaveRecord"), 0);
			}
		}
	}
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

	SaveRecord();
	SetGameState(ESGGameState::GameOver);
}


void ASpaceGameGameModeBase::SaveRecord()
{
	if (!GetWorld()->GetFirstPlayerController())
		return;

	const auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!Player)
		return;

	ASGPlayerState* PlayerStateOwner = Cast<ASGPlayerState>(Player->GetPlayerState());
	if (!PlayerStateOwner)
		return;

	const auto GameInstance = GetWorld()->GetGameInstance<USGGameInstance>();
	if (!GameInstance)
		return;

	USGSaveGame* SaveGameObject = Cast<USGSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveRecord"), 0));
	if (SaveGameObject)
	{
		int32 Record = std::max(PlayerStateOwner->GetNumberMeteoriteDestroyed(), GameInstance->GetRecordMeteoriteDestroyed());
		GameInstance->SetRecordMeteoriteDestroyed(Record);
		SaveGameObject->RecordMeteoriteDestroyed = Record;
		UGameplayStatics::SaveGameToSlot(SaveGameObject, TEXT("SaveRecord"), 0);
	}
}