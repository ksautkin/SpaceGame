#include "UI/SGPlayerHUDWidget.h"
#include "Components/SGWeaponComponent.h"
#include "Player/SGPlayerState.h"
#include "SGGameInstance.h"


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

int32 USGPlayerHUDWidget::GetPlayerStat() const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player)
		return 0;

	ASGPlayerState* PlayerStateOwner = Cast<ASGPlayerState>(Player->GetPlayerState());
	if (PlayerStateOwner)
	{
		return PlayerStateOwner->GetNumberMeteoriteDestroyed();
	}
	return 0;
}

int32 USGPlayerHUDWidget::GetRecord() const
{
	const auto GameInstance = GetWorld()->GetGameInstance<USGGameInstance>();
	if (!GameInstance)
		return 0;

	return GameInstance->GetRecordMeteoriteDestroyed();
}