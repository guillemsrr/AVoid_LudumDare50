// Copyright (c) Guillem Serra. All Rights Reserved.

#include "LevelDirector.h"

ALevelDirector::ALevelDirector()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALevelDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

