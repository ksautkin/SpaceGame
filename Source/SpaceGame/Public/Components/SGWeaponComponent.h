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
	// ������������ ���������� �������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TraceMaxDistance = 1500.0f;
	// ����. ���-�� ���������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	int32 MaxAmountShots = 20;
	// ����� ����������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TimeReload = 0.1f;
	// ������ �������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	UNiagaraSystem* TraceFX;
	// ��� ����� ������ �������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	FString TraceTargetName = "TraceTarget";
	// sound fire
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* FireSound;


	virtual void BeginPlay() override;
	// ������ ������� 
	void MakeShot();
	// ����������� �������� 
	void ReloadBlaster();
	// ����� ������� �������� 
	void SpawnTrace(const FVector& TraceStart, const FVector& TraceEnd);

private:
	// ������� ���-�� ���������
	int32 CurrentAmountShots = 20;
	// ������ ����������� 
	FTimerHandle ReloadTimerHandle;

};
