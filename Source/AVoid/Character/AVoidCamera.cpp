// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidCamera.h"

#include "Camera/CameraComponent.h"

AAVoidCamera::AAVoidCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	RootComponent = Root;
	FirstPersonCameraComponent->SetupAttachment(RootComponent);
}

void AAVoidCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAVoidCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

