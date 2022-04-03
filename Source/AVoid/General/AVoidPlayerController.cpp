// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidPlayerController.h"

#include "AVoidGameModeBase.h"

void AAVoidPlayerController::Initialize(AAVoidGameModeBase* GameMode)
{
	InputComponent->BindAction("Start", IE_Pressed, GameMode, &AAVoidGameModeBase::StartGame);
	InputComponent->BindAction("Restart", IE_Pressed, GameMode, &AAVoidGameModeBase::RestartGame);
}
