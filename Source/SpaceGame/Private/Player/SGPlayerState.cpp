#include "Player/SGPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogSGPlayerState, All, All);

void ASGPlayerState::LogInfo()
{
	UE_LOG(LogSGPlayerState, Display, TEXT("Destroyed: %i"), NumMeteoriteDestroyed);
}