// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AVoidCharacter.generated.h"

UCLASS()
class AVOID_API AAVoidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAVoidCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	class ULocomotion* Locomotion;
	UPROPERTY(EditDefaultsOnly)
	class UMechanics* Mechanics;
	
	virtual void BeginPlay() override;

private:
	bool bHasLight;

	void Throw();
	void ReleaseThrow();
	void StopThrow();
};
