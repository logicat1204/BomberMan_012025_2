// Fill out your copyright notice in the Description page of Project Settings.


#include "SegundoParcial/EnemigoVolador.h"

// Sets default values
AEnemigoVolador::AEnemigoVolador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaEV = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaEV"));
	ConstructorHelpers::FObjectFinder<USkeletalMesh> AssetVolador(TEXT("/Script/Engine.SkeletalMesh'/Game/Batron/Meshes/SK_Batron.SK_Batron'"));
	if (AssetVolador.Succeeded()) {
		MallaEV->SetSkeletalMesh(AssetVolador.Object);
	}
}

// Called when the game starts or when spawned
void AEnemigoVolador::BeginPlay()
{
	Super::BeginPlay();
	izq_der = FMath::RandBool();
	Pos_vieja = GetActorLocation();
    GetWorld()->GetTimerManager().SetTimer(THMovimientoVolador, this, &AEnemigoVolador::Moverse, 0.15f, true);
}

// Called every frame
void AEnemigoVolador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemigoVolador::Moverse()
{
    if (mov_actual < cant_movimientos)
    {
        // Mueve en la dirección actual
        FVector NuevaPosicion = GetActorLocation();
        float Movimiento = (izq_der ? 100.0f : -100.0f);
        NuevaPosicion.X += Movimiento;

        SetActorLocation(NuevaPosicion);

        mov_actual++;
    }
    else
    {
        // Cambia dirección y reinicia el ciclo
        izq_der = !izq_der;
        mov_actual = 0;
    }
}


