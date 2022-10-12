#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGSpawnEnemy.generated.h"

struct FTimerHandle;
class ASGMeteorite;

UCLASS()
class SPACEGAME_API ASGSpawnEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGSpawnEnemy();
	// �������� ����� ������
	UFUNCTION()
	void StartSpawnEnemy();
	// ������������� ����� ������ 
	void StopSpawnEnemy();
	
private:
	UPROPERTY()
	FTimerHandle SpawnTimerHandle;

protected:
	// ������������ �������� ������� ������ ���������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MaxTimeSpawn = 5.0f;
	// ����������� �������� ������� ������ ���������� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MinTimeSpawn = 1.0f;
	// �������� �� ������� ����������� ����� ������  
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float ValDecreaseTimeSpawn = 0.01f;
	// ������������ �������� ����������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MaxSpeedEnemy = 300.0f;
	// ������������ �������� ����������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MinSpeedEnemy = 100.0f;
	// �������� �� ������� ������������ �������� ����������  
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float ValIncreaseTimeSpawn = 5.0f;
	// ����� ������� ����������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ASGMeteorite> EnemySpawnType;

	virtual void BeginPlay() override;
};
