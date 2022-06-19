#include "Menu/SGMenuGameModeBase.h"
#include "Menu/SGMenuPlayerController.h"
#include "Menu/SGMenuHUD.h"

ASGMenuGameModeBase::ASGMenuGameModeBase()
{
	PlayerControllerClass = ASGMenuPlayerController::StaticClass();
	HUDClass = ASGMenuHUD::StaticClass();
}