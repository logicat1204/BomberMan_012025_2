// Fill out your copyright notice in the Description page of Project Settings.


#include "SegundoParcial/Comandante.h"

// Sets default values
AComandante::AComandante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaCOM = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaCOM"));
	ConstructorHelpers::FObjectFinder<USkeletalMesh> AssetVolador(TEXT("/Script/Engine.SkeletalMesh'/Game/MonsterForSurvivalGame/Mesh/Polyart/Beholder_SK.Beholder_SK'"));
	if (AssetVolador.Succeeded()) {
		MallaCOM->SetSkeletalMesh(AssetVolador.Object);
        MallaCOM->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
	}
}

// Called when the game starts or when spawned
void AComandante::BeginPlay()
{
	Super::BeginPlay();
    GetWorldTimerManager().SetTimer(THComMov, this, &AComandante::MoverCOM, 0.2f, true);
}

// Called every frame
void AComandante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FVector UltimaPosicionCOM; // Agregar esto en la clase para rastrear la última posición

void AComandante::MoverCOM()
{
    if (CPosicionesMover.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No hay espacios disponibles para moverse."));
        return;
    }

    FVector PosActual = GetActorLocation();
    FVector PosicionMasCercana = FVector::ZeroVector;
    float DistanciaMinima = FLT_MAX;

    for (const FVector& Espacio : CPosicionesMover)
    {
        float Distancia = FVector::Dist(PosActual, Espacio);

        // Evitar seleccionar la última posición usada
        if (Distancia > 0 && Distancia < DistanciaMinima && Espacio != UltimaPosicionCOM)
        {
            DistanciaMinima = Distancia;
            PosicionMasCercana = Espacio;
        }
    }

    if (!PosicionMasCercana.IsZero())
    {
        SetActorLocation(PosicionMasCercana);
        UltimaPosicionCOM = PosActual; // Guardar la posición anterior antes de moverse
        UE_LOG(LogTemp, Warning, TEXT("Enemigo movido a posición: %s"), *PosicionMasCercana.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No se encontró un nuevo espacio válido."));
    }
}

