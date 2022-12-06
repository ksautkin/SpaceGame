#include "Menu/SGMenuUserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SGGameInstance.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"


void USGMenuUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &USGMenuUserWidget::OnStartGame);
	}

	if (QuitGameButton)
	{
		QuitGameButton->OnClicked.AddDynamic(this, &USGMenuUserWidget::OnQuitGame);
	}

	if (SetNamePlayerWidget)
	{
		SetNamePlayerWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void USGMenuUserWidget::OnStartGame()
{
	if (!GetWorld())
		return;

	// play sound click button
	UAudioComponent* audioComponent = UGameplayStatics::SpawnSound2D(GetWorld(), ClickSound);
	audioComponent->OnAudioFinished.AddDynamic(this, &USGMenuUserWidget::OnSetNamePlayer);
}

void USGMenuUserWidget::OnSetNamePlayer()
{
	if (SetNamePlayerWidget)
	{
		SetNamePlayerWidget->SetVisibility(ESlateVisibility::Visible);
	}

	if (StartGameButton)
	{
		StartGameButton->SetVisibility(ESlateVisibility::Hidden);
	}

	if (QuitGameButton)
	{
		QuitGameButton->SetVisibility(ESlateVisibility::Hidden);
	}
}


void USGMenuUserWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}