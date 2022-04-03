// Copyright (c) Guillem Serra. All Rights Reserved.

#include "ObstacleSpawner.h"

// Sets default values for this component's properties
UObstacleSpawner::UObstacleSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UObstacleSpawner::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

