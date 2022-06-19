#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SGCoreTypes.h"
#include "SGPlayerController.generated.h"


UCLASS()
class SPACEGAME_API ASGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// ��������� ����� ���� 
	void OnGamePause();
	// ��������� ��������� ���� 
	void OnGameStateChanged(ESGGameState State);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
