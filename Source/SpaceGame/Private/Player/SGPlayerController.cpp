#include "Player/SGPlayerController.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceGame/SpaceGameGameModeBase.h"

void ASGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		if (const auto GameMode = Cast<ASpaceGameGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->OnGameStateChanged.AddUObject(this, &ASGPlayerController::OnGameStateChanged);
		}
	}
}

void ASGPlayerController::OnGamePause()
{
	if(!GetWorld() || !GetWorld()->GetAuthGameMode())
		return;

	GetWorld()->GetAuthGameMode()->SetPause(this);
}

void ASGPlayerController::OnGameStateChanged(ESGGameState State)
{
	if (State == ESGGameState::InProgress)
	{
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}

void ASGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!InputComponent)
		return;

	InputComponent->BindAction("PauseGame", IE_Pressed, this, &ASGPlayerController::OnGamePause);
}

