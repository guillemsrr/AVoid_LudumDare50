// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidCamera.h"

AAVoidCamera::AAVoidCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAVoidCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAVoidCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

