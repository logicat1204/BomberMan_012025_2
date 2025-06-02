// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/Facade/ParticleGodMode.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AParticleGodMode::AParticleGodMode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	static ConstructorHelpers::FObjectFinder<UParticleSystem> particulasGodmode(TEXT("/Game/StarterContent/Particles/P_Sparks.P_Sparks"));
	if (particulasGodmode.Succeeded())
	{
		PartycleGodMode = particulasGodmode.Object;
	}
}

// Called when the game starts or when spawned
void AParticleGodMode::BeginPlay()
{
	Super::BeginPlay();
	MyPlayer = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PartycleGodMode && MyPlayer)
	{
		ParticleInstance = UGameplayStatics::SpawnEmitterAttached(
			PartycleGodMode,
			MyPlayer->GetRootComponent(),       // Se adjunta al jugador
			NAME_None,                          // Nombre del socket
			FVector::ZeroVector,                // Offset relativo
			FRotator::ZeroRotator,             // Rotación
			FVector(2.0f),                      //ESCALA (2x en X, Y, Z)
			EAttachLocation::KeepRelativeOffset,
			true                                // AutoDestroy
		);                    // AutoDestroy
		GetWorldTimerManager().SetTimer(THDuracion, this, &AParticleGodMode::DestroyParticle, duracion_particle, false);
	}
}
// Called every frame
void AParticleGodMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AParticleGodMode::DestroyParticle()
{
	if (ParticleInstance)
	{
		ParticleInstance->DeactivateSystem();  // Detiene la emisión de partículas
		ParticleInstance->DestroyComponent();  // Elimina el componente de la escena
		ParticleInstance = nullptr;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Black, TEXT("Se ha destruido las particulas."));
	}
}

