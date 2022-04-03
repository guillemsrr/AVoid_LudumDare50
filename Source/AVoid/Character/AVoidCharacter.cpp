// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidCharacter.h"

#include "CharacterLight.h"
#include "Locomotion.h"
#include "Mechanics.h"
#include "AVoid/Utils/Debug.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"

AAVoidCharacter::AAVoidCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Locomotion = CreateDefaultSubobject<ULocomotion>("Locomotion");
	Mechanics = CreateDefaultSubobject<UMechanics>("Mechanics");
	DeathCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("SecondaryCapsuleComponent");

	DeathCapsuleComponent->SetupAttachment(RootComponent);
}

void AAVoidCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AAVoidCharacter::Hit);
	DeathCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AAVoidCharacter::Die);

	Mechanics->SetLight(LightActor);
	Mechanics->Recover();

	InitialLocation = GetActorLocation();
}

void AAVoidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveVertical", Locomotion, &ULocomotion::MoveVertical).bConsumeInput = false;
	PlayerInputComponent->BindAxis("MoveHorizontal", Locomotion, &ULocomotion::MoveHorizontal).bConsumeInput = false;
	PlayerInputComponent->BindAxis("LightVertical", this, &AAVoidCharacter::LightVertical).bConsumeInput = false;
	PlayerInputComponent->BindAxis("LightHorizontal", this, &AAVoidCharacter::LightHorizontal).bConsumeInput = false;
	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &AAVoidCharacter::StartThrow);
	PlayerInputComponent->BindAction("Throw", IE_Released, this, &AAVoidCharacter::ReleaseThrow);
	PlayerInputComponent->BindAction("StopThrow", IE_Pressed, this, &AAVoidCharacter::StopThrow);
}

void AAVoidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsThrowingLight)
	{
		Mechanics->Recover();
	}
}

void AAVoidCharacter::RestartCharacter()
{
	SetActorLocation(InitialLocation);
	Mechanics->Recover();
	OnCharacterRestartDelegate.Broadcast();
}

void AAVoidCharacter::StartThrow()
{
	bIsThrowingLight = true;
	Mechanics->Recover();
}

void AAVoidCharacter::ReleaseThrow()
{
	if (bIsThrowingLight)
	{
		bIsThrowingLight = false;
		Mechanics->Throw();
	}
}

void AAVoidCharacter::StopThrow()
{
	if (bIsThrowingLight)
	{
		bIsThrowingLight = false;
		Mechanics->StopThrow();
	}
}

void AAVoidCharacter::LightVertical(float Value)
{
	if (!bIsThrowingLight) return;
	
	Mechanics->LightVertical(Value);
}

void AAVoidCharacter::LightHorizontal(float Value)
{
	if (!bIsThrowingLight) return;

	Mechanics->LightHorizontal(Value);
}

void AAVoidCharacter::Die(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->ActorHasTag(FName("Light"))) return;
	if(OtherActor == this) return;
	
	OnCharacterDeadDelegate.Broadcast();
}

void AAVoidCharacter::Hit(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->ActorHasTag(FName("Light"))) return;
	
	DEBUG_LOG("HIT");
}
