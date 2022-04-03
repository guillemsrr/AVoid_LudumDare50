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

protected:
	virtual void BeginPlay() override;
};
