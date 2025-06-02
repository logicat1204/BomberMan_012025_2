// Fill out your copyright notice in the Description page of Project Settings.


#include "SegundoParcial/EnemigoNormal.h"

// Sets default values
AEnemigoNormal::AEnemigoNormal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaEN = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaEN"));
	ConstructorHelpers::FObjectFinder<USkeletalMesh> AssetEN(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'"));
	if (AssetEN.Succeeded()) {
		MallaEN->SetSkeletalMesh(AssetEN.Object);
	}
}

// Called when the game starts or when spawned
void AEnemigoNormal::BeginPlay()
{
	Super::BeginPlay();
    GetWorldTimerManager().SetTimer(THMovEnemN, this, &AEnemigoNormal::mover_espacios, 1.0f, true);
}

// Called every frame
void AEnemigoNormal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector UltimaPosicion; // Agregar esto en la clase para rastrear la última posición

void AEnemigoNormal::mover_espacios()
{
    if (ENPosicionesMover.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No hay espacios disponibles para moverse."));
        return;
    }

    FVector PosActual = GetActorLocation();
    FVector PosicionMasCercana = FVector::ZeroVector;
    float DistanciaMinima = FLT_MAX;

    for (const FVector& Espacio : ENPosicionesMover)
    {
        float Distancia = FVector::Dist(PosActual, Espacio);

        // Evitar seleccionar la última posición usada
        if (Distancia > 0 && Distancia < DistanciaMinima && Espacio != UltimaPosicion)
        {
            DistanciaMinima = Distancia;
            PosicionMasCercana = Espacio;
        }
    }

    if (!PosicionMasCercana.IsZero())
    {
        SetActorLocation(PosicionMasCercana);
        UltimaPosicion = PosActual; // Guardar la posición anterior antes de moverse
        UE_LOG(LogTemp, Warning, TEXT("Enemigo movido a posición: %s"), *PosicionMasCercana.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No se encontró un nuevo espacio válido."));
    }
}

