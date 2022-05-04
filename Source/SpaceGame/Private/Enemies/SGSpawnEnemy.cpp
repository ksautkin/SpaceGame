#include "Enemies/SGSpawnEnemy.h"
#include "TimerManager.h"
#include "Enemies/SGMeteorite.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


ASGSpawnEnemy::ASGSpawnEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASGSpawnEnemy::BeginPlay()
{
	Super::BeginPlay();
	StartSpawnEnemy();
}

void ASGSpawnEnemy::StartSpawnEnemy()
{
	float SpeedEnemy = FMath::FRandRange(MinSpeedEnemy, MaxSpeedEnemy);
	// спавн метеорита относительно объекта спавана 
	ASGMeteorite* SpawnEnemy = (ASGMeteorite*)(GetWorld()->SpawnActorDeferred<ASGMeteorite>(EnemySpawnType, GetTransform(), this));
	SpawnEnemy->SetSpeedMeteorite(SpeedEnemy);
	UGameplayStatics::FinishSpawningActor(SpawnEnemy, GetTransform());

	SpawnTimerHandle;
	float DelayTime = FMath::FRandRange(MinTimeSpawn, MaxTimeSpawn);
	// спавн метеорита с задержкой 
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASGSpawnEnemy::StartSpawnEnemy, DelayTime, false);
	// увеличение скорости каждый спавн 
	MinSpeedEnemy += 5.0f;
	MaxSpeedEnemy += 5.0f;
}

void ASGSpawnEnemy::StopSpawnEnemy()
{
	// отсановка спавана 
	GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
}

