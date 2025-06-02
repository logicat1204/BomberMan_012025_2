// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Facade/Facade_GodMode.h"

// Sets default values
AFacade_GodMode::AFacade_GodMode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacade_GodMode::BeginPlay()
{
	Super::BeginPlay();
	BombTurbo=GetWorld()->SpawnActor<ABombTurboMode>(ABombTurboMode::StaticClass(), FVector(0.0f,0.0f,0.0f), FRotator(0.0f, 0.0f, 0.0f));
	SpeedBoost=GetWorld()->SpawnActor<ASpeedBoost>(ASpeedBoost::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Particles=GetWorld()->SpawnActor<AParticleGodMode>(AParticleGodMode::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	GetWorldTimerManager().SetTimer(THDuration, this, &AFacade_GodMode::Off, duration, false);
}

// Called every frame
void AFacade_GodMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacade_GodMode::Off()
{
	if (BombTurbo) {
		BombTurbo->Destroy();
	}
	if (SpeedBoost) {
		SpeedBoost->Destroy();
	}
	if (Particles) {
		Particles->Destroy();
	}
}

