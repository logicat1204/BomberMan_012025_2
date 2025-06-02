// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Builder/BuilderNivelGrande.h"

ABordes* ABuilderNivelGrande::ConstruirBordes()
{
	ABordes* Bordes = GetWorld()->SpawnActor<ABordes>(ABordes::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Bordes->AsignarTamano(100.0f, 100.0f);
	return Bordes;
}

AObstaculos* ABuilderNivelGrande::ConstruirObstaculos()
{
	AObstaculos* Obstaculos = GetWorld()->SpawnActor<AObstaculos>(AObstaculos::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Obstaculos->AsignarTamano(100.0f, 100.0f);
	return Obstaculos;
}
