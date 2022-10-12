#include "UI/SGPauseWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"


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

	// play sound click button
	UGameplayStatics::SpawnSound2D(GetWorld(), ClickSound);

	GetWorld()->GetAuthGameMode()->ClearPause();
}