// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelDirector.generated.h"

UCLASS()
class AVOID_API ALevelDirector : public AActor
{
	GENERATED_BODY()

public:
	ALevelDirector();

	virtual void Tick(float DeltaTime) override;

	void Start();
	void Stop();

protected:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* Root;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere)
	float SpawnTimer;

	UPROPERTY(EditAnywhere)
	float SpawnPositionOffset;

	float Test;

	UPROPERTY(EditAnywhere)
	float Gravity;

	UPROPERTY(EditInstanceOnly)
	TArray<AActor*> AlreadyPlacedActors;
	
	virtual void BeginPlay() override;

private:
	FVector InitialLocation;
	FVector Location;
	FActorSpawnParameters SpawnParameters;
	FTimerHandle TimerHandle;
	TQueue<AActor*> Spawns;

	UFUNCTION()
	void SpawnWell();
};
