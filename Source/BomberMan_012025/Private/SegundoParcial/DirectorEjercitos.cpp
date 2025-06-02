// Fill out your copyright notice in the Description page of Project Settings.


#include "SegundoParcial/DirectorEjercitos.h"

// Sets default values
ADirectorEjercitos::ADirectorEjercitos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorEjercitos::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADirectorEjercitos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorEjercitos::SetEspaciosColocarEnemigos(TArray<FVector> EspaciosC)
{
	EspaciosColocar = EspaciosC;
}

void ADirectorEjercitos::SetBuilder(IBuilderEjercitoEnemigos* NuevoBuilder)
{
	Builder = NuevoBuilder;
}

void ADirectorEjercitos::CrearEjercito()
{
	Builder->AsignarEspaciosEnBlanco(EspaciosColocar);
	Builder->CrearEnemigosNormales(10);
	Builder->CrearEnemigosVoladores(5);
	Builder->CrearComandante();
	Ejercito = Builder->ObtenerEjercito();
}
