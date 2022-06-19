#include "Menu/SGMenuUserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SGGameInstance.h"


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
}

void USGMenuUserWidget::OnStartGame()
{
	if (!GetWorld())
		return;

	const auto SGGameInstance = GetWorld()->GetGameInstance<USGGameInstance>();
	if (!SGGameInstance)
		return;

	if (SGGameInstance->GetStartupLevelName().IsNone())
		return;

	UGameplayStatics::OpenLevel(this, FName(SGGameInstance->GetStartupLevelName()));
}

void USGMenuUserWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}