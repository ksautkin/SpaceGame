#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SGWeaponComponent.generated.h"

class UNiagaraSystem;
class USoundCue;

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
	// максимальное рассто€ние выстрела 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TraceMaxDistance = 1500.0f;
	// макс. кол-во выстрелов
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	int32 MaxAmountShots = 20;
	// врем€ перезар€дки 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TimeReload = 0.1f;
	// эффект выстрела 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	UNiagaraSystem* TraceFX;
	// им€ точки кненой выстрела 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	FString TraceTargetName = "TraceTarget";
	// sound fire
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* FireSound;


	virtual void BeginPlay() override;
	// делает выстрел 
	void MakeShot();
	// перезар€дка бластера 
	void ReloadBlaster();
	// спавн эффекта вытсрела 
	void SpawnTrace(const FVector& TraceStart, const FVector& TraceEnd);

private:
	// текущее кол-во выстрелов
	int32 CurrentAmountShots = 20;
	// таймер перезар€дки 
	FTimerHandle ReloadTimerHandle;

};
