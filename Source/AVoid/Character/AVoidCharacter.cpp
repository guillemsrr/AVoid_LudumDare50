// "// Copyright (c) Guillem Serra. All Rights Reserved."

#include "AVoidCharacter.h"

// Sets default values
AAVoidCharacter::AAVoidCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAVoidCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAVoidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAVoidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

