// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidCharacter.h"

#include "Locomotion.h"
#include "Mechanics.h"

AAVoidCharacter::AAVoidCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Locomotion = CreateDefaultSubobject<ULocomotion>("Locomotion");
	Mechanics = CreateDefaultSubobject<UMechanics>("Mechanics");


}

void AAVoidCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAVoidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAVoidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveVertical", Locomotion, &ULocomotion::MoveVertical).bConsumeInput = false;
	PlayerInputComponent->BindAxis("MoveHorizontal", Locomotion, &ULocomotion::MoveHorizontal).bConsumeInput = false;
	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &AAVoidCharacter::Throw);
	PlayerInputComponent->BindAction("Throw", IE_Released,  this, &AAVoidCharacter::ReleaseThrow);
	PlayerInputComponent->BindAction("StopThrow", IE_Pressed,  this, &AAVoidCharacter::StopThrow);
}

void AAVoidCharacter::Throw()
{
	if(bHasLight)
	{
		Mechanics->StartThrow();
	}
	else
	{
		Mechanics->Recover();
	}
}

void AAVoidCharacter::ReleaseThrow()
{
	if(bHasLight)
	{
		Mechanics->Throw();
	}
}

void AAVoidCharacter::StopThrow()
{
	if(bHasLight)
	{
		Mechanics->StopThrow();
	}
}

