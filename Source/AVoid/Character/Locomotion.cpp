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
	
	MovementVector += GetOwner()->GetActorUpVector() * Value*MovementSpeed;
}

void ULocomotion::MoveHorizontal(float Value)
{
	if (Value == 0.0f) return;

	MovementVector += GetOwner()->GetActorRightVector() * Value*MovementSpeed;
}

void ULocomotion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ApplyMovementFriction();
	GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + MovementVector*DeltaTime);
}

void ULocomotion::ApplyMovementFriction()
{
	FVector Direction = MovementVector;
	Direction.Normalize();
	MovementVector -= Direction*(MovementSpeed/FrictionRelation);
}

void ULocomotion::ApplyGravity()
{
	MovementVector-= FVector(0.5*GravityForce, 0, 0);
}

