// Fill out your copyright notice in the Description page of Project Settings.


#include "BombBot.h"

// Sets default values
ABombBot::ABombBot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABombBot::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABombBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABombBot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Configurar Movimiento
	PlayerInputComponent->BindAxis("MoveForward", this, &ABombBot::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABombBot::MoveRight);

	// Configurar Salto
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABombBot::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABombBot::StopJump);
}

void ABombBot::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ABombBot::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void ABombBot::StartJump()
{
	Jump();
}

void ABombBot::StopJump()
{
	StopJumping();
}