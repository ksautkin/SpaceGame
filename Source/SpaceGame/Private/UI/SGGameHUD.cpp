#include "UI/SGGameHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"
#include "SpaceGame/SpaceGameGameModeBase.h"


void  ASGGameHUD::OnGameStateChanged(ESGGameState State)
{
	if (CurrentGameWidget)
	{
		CurrentGameWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (GameWidgets.Contains(State))
	{
		CurrentGameWidget = GameWidgets[State];
		if(CurrentGameWidget)
			CurrentGameWidget->SetVisibility(ESlateVisibility::Visible);
	}
}


void ASGGameHUD::BeginPlay()
{
	Super::BeginPlay();

	GameWidgets.Add(ESGGameState::InProgress, CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass));
	GameWidgets.Add(ESGGameState::Pause, CreateWidget<UUserWidget>(GetWorld(), PauseWidgetClass)); 
	GameWidgets.Add(ESGGameState::GameOver, CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass));

	for (auto GameWidgetPair : GameWidgets)
	{
		const auto GameWidget = GameWidgetPair.Value;
		if (!GameWidget)
			continue;

		GameWidget->AddToViewport();
		GameWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (GetWorld())
	{
		if (const auto GameMode = Cast<ASpaceGameGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->OnGameStateChanged.AddUObject(this, &ASGGameHUD::OnGameStateChanged);
		}
	}
}