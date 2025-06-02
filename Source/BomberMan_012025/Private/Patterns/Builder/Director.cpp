// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Builder/Director.h"

// Sets default values
ADirector::ADirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirector::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirector::AsignarBuilder(ABuilderNivel* nuevo_builder)
{
	Builder = nuevo_builder;
}

void ADirector::CrearNivel(FVector coor_colocar)
{
	NivelPersonalizado = GetWorld()->SpawnActor<ANivel>(ANivel::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	NivelPersonalizado->location = coor_colocar;
	NivelPersonalizado->Obstaculos = Builder->ConstruirObstaculos();
	NivelPersonalizado->Bordes = Builder->ConstruirBordes();
	NivelPersonalizado->Colocar();
}

