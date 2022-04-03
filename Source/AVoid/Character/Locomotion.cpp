// Copyright (c) Guillem Serra. All Rights Reserved.

#include "Locomotion.h"

#include "AVoid/Utils/Debug.h"

#include "GameFramework/Character.h"

ULocomotion::ULocomotion()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULocomotion::Initialize()
{
	
}

void ULocomotion::BeginPlay()
{
	Super::BeginPlay();
}

void ULocomotion::MoveVertical(float Value)
{
	if (Value == 0.0f) return;
	
	InputVector += GetOwner()->GetActorUpVector() * Value;
}

void ULocomotion::MoveHorizontal(float Value)
{
	if (Value == 0.0f) return;

	InputVector += GetOwner()->GetActorRightVector() * Value;
}

void ULocomotion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	InputVector.Normalize();
	InputVector*=MaxMovementSpeed;
	MovementVector+=InputVector;
	ApplyMovementFriction();
	
	DEBUG_LOG_TICK(MovementVector.ToString());
	GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + MovementVector*DeltaTime*MovementSpeed);
	InputVector = FVector(0);
}

void ULocomotion::ApplyMovementFriction()
{
	FVector Direction = MovementVector;
	Direction.Normalize();
	MovementVector -= Direction*(MovementSpeed/FrictionRelation);
}

