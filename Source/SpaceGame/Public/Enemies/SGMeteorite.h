#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGMeteorite.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class URotatingMovementComponent;
class UNiagaraSystem;
class USoundCue;

UCLASS()
class SPACEGAME_API ASGMeteorite : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGMeteorite();
	virtual void OnConstruction(const FTransform& Transform) override;
	// установка скорости метеорита 
	void SetSpeedMeteorite(float& Speed) { SpeedMeteorite = Speed; }
	// возврат скорости метеорита
	float GetSpeedMeteorite() const { return SpeedMeteorite; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	URotatingMovementComponent* RotatingMovementComponent;
	// скорость метеорита
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float SpeedMeteorite = 10.0f;
	// размер метеорита
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Scale")
	float MinScaleMeteorite = 1.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Scale")
	float MaxScaleMeteorite = 5.0f;
	// эффект уничтожения 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Destroy")
	UNiagaraSystem* TraceFX;
	// sound destroy
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* DestroySound;
 
	virtual void BeginPlay() override;
	// фунция пересечения метеорита и корабля или метеорита с другми метеоритом
	UFUNCTION()
	void OnBeginOverllap(AActor* OverlappedActor, AActor* OtherActor);

public:	
	virtual void Tick(float DeltaTime) override;
	bool Destroy(bool bNetForce = false, bool bShouldModifyLevel = true);


};
