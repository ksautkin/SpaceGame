#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SGWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEGAME_API USGWeaponComponent : public UActorComponent
{
	GENERATED_BODY()
	

public:	
	USGWeaponComponent();
	void Fire();
	int32 GetMaxAmountShots() const;
	int32 GetCurrentAmountShots() const;

protected:
	// максимальное расстояние выстрела 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TraceMaxDistance = 1500.0f;
	// макс. кол-во выстрелов
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	int32 MaxAmountShots = 20;
	// время перезарядки 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TimeReload = 0.1f;

	virtual void BeginPlay() override;
	// делает выстрел 
	void MakeShot();
	// перезарядка бластера 
	void ReloadBlaster();

private:
	// текущее кол-во выстрелов
	int32 CurrentAmountShots = 20;
	// таймер перезарядки 
	FTimerHandle ReloadTimerHandle;

};
