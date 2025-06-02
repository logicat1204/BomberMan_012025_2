// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/Facade/SpeedBoost.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASpeedBoost::ASpeedBoost()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpeedBoost::BeginPlay()
{
	Super::BeginPlay();
	IncreasePlayerSpeed();
	GetWorldTimerManager().SetTimer(THDefaultSpeed, this, &ASpeedBoost::ResetPlayerSpeed, set_default_time, false);
}

// Called every frame
void ASpeedBoost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpeedBoost::IncreasePlayerSpeed()
{
	MyPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	default_speed = MyPlayer->GetCharacterMovement()->MaxWalkSpeed;
	if (MyPlayer)
	{
		MyPlayer->GetCharacterMovement()->MaxWalkSpeed = 2000.0f;
	}

}

void ASpeedBoost::ResetPlayerSpeed()
{
	MyPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (MyPlayer)
	{
		MyPlayer->GetCharacterMovement()->MaxWalkSpeed = default_speed;
	}
}

