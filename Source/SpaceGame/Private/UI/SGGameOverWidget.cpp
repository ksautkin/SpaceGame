#include "UI/SGGameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

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
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}