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
	// ������������ ���������� �������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TraceMaxDistance = 1500.0f;
	// ����. ���-�� ���������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	int32 MaxAmountShots = 20;
	// ����� ����������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blaster")
	float TimeReload = 0.1f;

	virtual void BeginPlay() override;
	// ������ ������� 
	void MakeShot();
	// ����������� �������� 
	void ReloadBlaster();

private:
	// ������� ���-�� ���������
	int32 CurrentAmountShots = 20;
	// ������ ����������� 
	FTimerHandle ReloadTimerHandle;

};
