#pragma once

#include "SGCoreTypes.generated.h"

UENUM(BlueprintType)
enum class ESGGameState : uint8
{
    WaitingToStart = 0,
    InProgress,
    Pause,
    GameOver
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameStateChangedSignature, ESGGameState);