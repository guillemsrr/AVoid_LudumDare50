// Copyright (c) Guillem Serra. All Rights Reserved.

#include "CharacterLight.h"

ACharacterLight::ACharacterLight()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacterLight::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

