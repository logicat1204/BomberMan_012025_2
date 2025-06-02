// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/BuilderNuevo/DirectorNiveles.h"

// Sets default values
ADirectorNiveles::ADirectorNiveles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorNiveles::BeginPlay()
{
	Super::BeginPlay();
	ConstruirNivel();
}

// Called every frame
void ADirectorNiveles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorNiveles::SetBuilder(ABuilderNivelAleatorio* BuilderNuevo)
{
	Builder = BuilderNuevo;
}

void ADirectorNiveles::ConstruirNivel()
{
	Builder = GetWorld()->SpawnActor<ABuilderNivelAleatorio>(ABuilderNivelAleatorio::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
	posColocar1 = FVector(1645.0f, 1250.0f, 0.0f);posColocar2 = FVector(2960.0f, -65.0f, 0.0f);
	Builder->SeleccionarLugarConstruccion(posColocar1, posColocar2);
	Builder->CrearTerreno();
	Builder->CrearMuros();
	Builder->CrearObstaculos(20);
}



