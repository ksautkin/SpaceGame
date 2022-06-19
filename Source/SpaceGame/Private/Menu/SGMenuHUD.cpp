#include "Menu/SGMenuHUD.h"
#include "Menu/SGMenuUserWidget.h"

void ASGMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (const auto MenuWidget = CreateWidget<USGMenuUserWidget>(GetWorld(), MenuWidgetClass))
	{
		MenuWidget->AddToViewport();
		MenuWidget->SetVisibility(ESlateVisibility::Visible);

	}

}