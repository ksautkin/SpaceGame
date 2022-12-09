#include "UI/SGGameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"


void USGGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ResetLevelButton)
	{
		ResetLevelButton->OnClicked.AddDynamic(this, &USGGameOverWidget::OnResetLevel);
	}
}

void USGGameOverWidget::OnResetLevel()
{
	if (!GetWorld())
		return;

	// play sound click button
	UAudioComponent* audioComponent = UGameplayStatics::SpawnSound2D(GetWorld(), ClickSound);
	audioComponent->OnAudioFinished.AddDynamic(this, &USGGameOverWidget::OnChangeLevel);
}

void USGGameOverWidget::OnChangeLevel()
{
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}
