#include "UI/SGGoToMenuWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "SGGameInstance.h"


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

	const auto SGGameInstance = GetWorld()->GetGameInstance<USGGameInstance>();
	if (!SGGameInstance)
		return;

	if (SGGameInstance->GetMenuLevelName().IsNone())
		return;

	UGameplayStatics::OpenLevel(this, FName(SGGameInstance->GetMenuLevelName()));
}