// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Mechanics.generated.h"

UCLASS()
class AVOID_API UMechanics : public UActorComponent
{
	GENERATED_BODY()

public:
	void StartThrow();
	void StopThrow();
	void Throw();
	void Recover();
};
