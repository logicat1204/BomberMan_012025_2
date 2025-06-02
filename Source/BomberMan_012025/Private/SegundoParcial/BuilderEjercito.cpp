// Fill out your copyright notice in the Description page of Project Settings.

#include "SegundoParcial/BuilderEjercito.h"
#include "SegundoParcial/EnemigoNormal.h"
#include "SegundoParcial/EnemigoVolador.h"
#include "SegundoParcial/Comandante.h"


// Sets default values
ABuilderEjercito::ABuilderEjercito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderEjercito::BeginPlay()
{
	Super::BeginPlay();
	Ejercito = GetWorld()->SpawnActor<AEjercito>(AEjercito::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
}

// Called every frame
void ABuilderEjercito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderEjercito::AsignarEspaciosEnBlanco(TArray<FVector> Espacios)
{
	EspaciosDisponibles = Espacios;
}

void ABuilderEjercito::CrearEnemigosNormales(int32 cant_enemigos)
{
	for (int32 i = 0; i < cant_enemigos; i++)
	{
		int32 pos_selec = FMath::RandRange(0, EspaciosDisponibles.Num());
		FVector pos_set = EspaciosDisponibles[pos_selec];
		AEnemigoNormal* EnemigoNormal = GetWorld()->SpawnActor<AEnemigoNormal>(AEnemigoNormal::StaticClass(), pos_set, FRotator::ZeroRotator);
		EnemigoNormal->ENPosicionesMover = EspaciosDisponibles;
		Ejercito->EnemigosNormales.Add(EnemigoNormal);
	}
}

void ABuilderEjercito::CrearEnemigosVoladores(int32 cant_enemigos)
{
	for (int32 i = 0; i < cant_enemigos; i++)
	{
		int32 pos_selec = FMath::RandRange(0, EspaciosDisponibles.Num());
		FVector pos_set = EspaciosDisponibles[pos_selec];
		AEnemigoVolador* EnemigoVolador = GetWorld()->SpawnActor<AEnemigoVolador>(AEnemigoVolador::StaticClass(), FVector(pos_set.X,pos_set.Y,pos_set.Z+500.0f), FRotator::ZeroRotator);
		Ejercito->EnemigosVoladores.Add(EnemigoVolador);
	}
}

void ABuilderEjercito::CrearComandante()
{
	int32 pos_selec = FMath::RandRange(0, EspaciosDisponibles.Num());
	FVector pos_set = EspaciosDisponibles[pos_selec];
	AComandante* ComandanteCreado = GetWorld()->SpawnActor<AComandante>(AComandante::StaticClass(), pos_set, FRotator::ZeroRotator);
	ComandanteCreado->CPosicionesMover = EspaciosDisponibles;
	Ejercito->Comandante = ComandanteCreado;
}

AEjercito* ABuilderEjercito::ObtenerEjercito()
{
	if (Ejercito)
	{
		return Ejercito;
	}
	return nullptr;
}

