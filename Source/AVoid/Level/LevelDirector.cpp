// Copyright (c) Guillem Serra. All Rights Reserved.

#include "LevelDirector.h"

#include "AVoid/Utils/Debug.h"

#include "Kismet/KismetMathLibrary.h"

ALevelDirector::ALevelDirector()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");

	RootComponent = Root;
}

void ALevelDirector::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = Root->GetComponentLocation();// +  FVector(SpawnPositionOffset, 0, 0);
	Location = InitialLocation;

	for (AActor* AlreadyPlacedActor : AlreadyPlacedActors)
	{
		Spawns.Enqueue(AlreadyPlacedActor);
		Spawns.Enqueue(AlreadyPlacedActor);
	}
	Stop();
	//SpawnTimer = SpawnPositionOffset/Gravity;
}

void ALevelDirector::SpawnWell()
{
	FRotator Rotation = FRotator(0, 0, UKismetMathLibrary::RandomFloatInRange(0, 360));
	AActor* Actor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, InitialLocation +  FVector(SpawnPositionOffset, 0, 0), Rotation, SpawnParameters);
	Actor->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);
	Spawns.Enqueue(Actor);

	AActor* ActorToRemove;
	Spawns.Dequeue(ActorToRemove);
	ActorToRemove->Destroy();
}

void ALevelDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Location+=FVector(-1,0,0)*Gravity;
	Root->SetWorldLocation(Location);

	float Mod = FMath::Fmod(FMath::Abs(Location.X), 7500.f);
	if(FMath::IsNearlyEqual(Mod, 7500.f, 100.f))
	{
		SpawnWell();
	}
}

void ALevelDirector::Start()
{
	SetActorTickEnabled(true);
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALevelDirector::SpawnWell, SpawnTimer, true);
}

void ALevelDirector::Stop()
{
	SetActorTickEnabled(false);
	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

