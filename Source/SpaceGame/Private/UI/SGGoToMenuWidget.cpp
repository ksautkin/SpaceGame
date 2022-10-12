#include "UI/SGGoToMenuWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "SGGameInstance.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"


void USGGoToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoToMenuButton)
	{
		GoToMenuButton->OnClicked.AddDynamic(this, &USGGoToMenuWidget::OnGoToMenu);
	}
}

void USGGoToMenuWidget::OnGoToMenu()
{
	if (!GetWorld())
		return;

	// play sound click button
	UAudioComponent*  audioComponent = UGameplayStatics::SpawnSound2D(GetWorld(), ClickSound);
	audioComponent->OnAudioFinished.AddDynamic(this, &USGGoToMenuWidget::OnChangeLevel);
}

void USGGoToMenuWidget::OnChangeLevel()
{
	const auto SGGameInstance = GetWorld()->GetGameInstance<USGGameInstance>();
	if (!SGGameInstance)
		return;

	if (SGGameInstance->GetMenuLevelName().IsNone())
		return;

	UGameplayStatics::OpenLevel(this, FName(SGGameInstance->GetMenuLevelName()));
}