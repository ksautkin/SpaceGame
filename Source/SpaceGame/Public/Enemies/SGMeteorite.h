#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGMeteorite.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class URotatingMovementComponent;

UCLASS()
class SPACEGAME_API ASGMeteorite : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGMeteorite();
	virtual void OnConstruction(const FTransform& Transform) override;
	// ��������� �������� ��������� 
	void SetSpeedMeteorite(float& Speed) { SpeedMeteorite = Speed; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	URotatingMovementComponent* RotatingMovementComponent;
	// �������� ���������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float SpeedMeteorite = 10.0f;
	// ������ ���������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Scale")
	float MinScaleMeteorite = 1.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Scale")
	float MaxScaleMeteorite = 5.0f;
 
	virtual void BeginPlay() override;
	// ������ ����������� ��������� � ������� 
	UFUNCTION()
	void OnBeginOverllap(AActor* OverlappedActor, AActor* OtherActor);

public:	
	virtual void Tick(float DeltaTime) override;

};
