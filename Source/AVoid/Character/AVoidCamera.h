// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AVoidCamera.generated.h"

UCLASS()
class AVOID_API AAVoidCamera : public AActor
{
	GENERATED_BODY()

public:
	AAVoidCamera();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
