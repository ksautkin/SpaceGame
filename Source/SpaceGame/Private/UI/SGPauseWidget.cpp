#include "UI/SGPauseWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

void USGPauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ClearPauseButton)
	{
		ClearPauseButton->OnClicked.AddDynamic(this, &USGPauseWidget::OnClearPause);
	}
}

void USGPauseWidget::OnClearPause()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
		return;

	GetWorld()->GetAuthGameMode()->ClearPause();
}