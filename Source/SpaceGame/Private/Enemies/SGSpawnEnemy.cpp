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
	// ����� ��������� ������������ ������� ������� 
	ASGMeteorite* SpawnEnemy = (ASGMeteorite*)(GetWorld()->SpawnActorDeferred<ASGMeteorite>(EnemySpawnType, GetTransform(), this));
	SpawnEnemy->SetSpeedMeteorite(SpeedEnemy);
	UGameplayStatics::FinishSpawningActor(SpawnEnemy, GetTransform());

	SpawnTimerHandle;
	float DelayTime = FMath::FRandRange(MinTimeSpawn, MaxTimeSpawn);
	// ����� ��������� � ��������� 
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASGSpawnEnemy::StartSpawnEnemy, DelayTime, false);
	// ���������� �������� ������ ����� 
	MinSpeedEnemy += 5.0f;
	MaxSpeedEnemy += 5.0f;
}

void ASGSpawnEnemy::StopSpawnEnemy()
{
	// ��������� ������� 
	GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
}

