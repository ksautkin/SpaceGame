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
	// начинает спавн актора
	UFUNCTION()
	void StartSpawnEnemy();
	// останавливает спавн актора 
	void StopSpawnEnemy();
	
private:
	UPROPERTY()
	FTimerHandle SpawnTimerHandle;

protected:
	// максимальная задержка времени спавна противника 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MaxTimeSpawn = 5.0f;
	// минимальная задержка времени спавна противника 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MinTimeSpawn = 1.0f;
	// значеине на которое уменьшается время спвана  
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float ValDecreaseTimeSpawn = 0.01f;
	// максимальная скорость противника
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MaxSpeedEnemy = 300.0f;
	// максимальная скорость противника
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float MinSpeedEnemy = 100.0f;
	// значеине на которое увеличвается скорость противника  
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	float ValIncreaseTimeSpawn = 5.0f;
	// актор который спавонится
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ASGMeteorite> EnemySpawnType;

	virtual void BeginPlay() override;
};
