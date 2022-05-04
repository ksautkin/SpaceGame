// Copyright Epic Games, Inc. All Rights Reserved.


#include "SpaceGameGameModeBase.h"
#include "GameFramework/GameMode.h"
#include "Player/SGBaseCharacter.h"
#include "Player/SGPlayerController.h"
#include "Enemies/SGSpawnEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/GameMode.h"


ASpaceGameGameModeBase::ASpaceGameGameModeBase()
{
	// установка классов GameMode по умолчанию 
	DefaultPawnClass = ASGBaseCharacter::StaticClass();
	PlayerControllerClass = ASGPlayerController::StaticClass();
}

void ASpaceGameGameModeBase::GameOver()
{
	//TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASGSpawnEnemy::StaticClass(), FoundActors);
	//// остановка всех спаунов 
	//for (auto FoundActor : FoundActors)
	//{
	//	ASGSpawnEnemy* SpawnEnemy = Cast<ASGSpawnEnemy>(FoundActor);
	//	if (SpawnEnemy)
	//		SpawnEnemy->StopSpawnEnemy();
	//}
	
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}
