// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/Facade/BombTurboMode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABombTurboMode::ABombTurboMode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABombTurboMode::BeginPlay()
{
	Super::BeginPlay();
	ACharacter* BaseCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	Player = Cast<ABomberMan_012025Character>(BaseCharacter);

	if (Player)
	{
		Player->CantBombas = 5;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("CantBombas seteado a 5"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("No se pudo castear el personaje"));
	}
	GetWorldTimerManager().SetTimer(THNormalSetTimer, this, &ABombTurboMode::ResetNormal, time_to_normal, false);
}

// Called every frame
void ABombTurboMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABombTurboMode::ResetNormal()
{
	ACharacter* BaseCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	Player = Cast<ABomberMan_012025Character>(BaseCharacter);
	if (Player)
	{
		Player->CantBombas = 1;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("CantBombas reseteado."));
	}
}

