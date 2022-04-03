// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterLight.generated.h"

UCLASS()
class AVOID_API ACharacterLight : public AActor
{
	GENERATED_BODY()

public:
	ACharacterLight();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
