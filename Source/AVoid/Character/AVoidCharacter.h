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

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterDeadSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterRestartSignature);

	UPROPERTY(BlueprintAssignable)
	FCharacterDeadSignature OnCharacterDeadDelegate;
	
	UPROPERTY(BlueprintAssignable)
	FCharacterRestartSignature OnCharacterRestartDelegate;

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void RestartCharacter();

protected:
	UPROPERTY(EditDefaultsOnly)
	class ULocomotion* Locomotion;
	UPROPERTY(EditDefaultsOnly)
	class UMechanics* Mechanics;
	UPROPERTY(EditDefaultsOnly)
	class UCapsuleComponent* DeathCapsuleComponent;

	virtual void BeginPlay() override;

private:
	bool bIsThrowingLight;
	FVector InitialLocation;

	void StartThrow();
	void ReleaseThrow();
	void StopThrow();

	void LightVertical(float Value);
	void LightHorizontal(float Value);

	UPROPERTY(EditInstanceOnly)
	class ACharacterLight* LightActor;
	
	UFUNCTION()
	void Die(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void Hit(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
