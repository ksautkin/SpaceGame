#include "UI/SGPlayerHUDWidget.h"
#include "Components/SGWeaponComponent.h"


float USGPlayerHUDWidget::GetAmountShotsPercent() const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player)
		return 0.0f;
	
	// получение компаненета оружия
	const auto Component = Player->GetComponentByClass(USGWeaponComponent::StaticClass());
	const auto WeaponComponent = Cast<USGWeaponComponent>(Component);
	if (!WeaponComponent)
		return 0.0f;
	// высчитвание процента 
	float percent = float(WeaponComponent->GetCurrentAmountShots())/float(WeaponComponent->GetMaxAmountShots());
	return percent;
}