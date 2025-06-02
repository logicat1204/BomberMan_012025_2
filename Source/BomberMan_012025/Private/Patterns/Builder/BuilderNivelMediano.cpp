// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Builder/BuilderNivelMediano.h"

ABordes* ABuilderNivelMediano::ConstruirBordes()
{
	ABordes* Bordes = GetWorld()->SpawnActor<ABordes>(ABordes::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Bordes->AsignarTamano(50.0f, 50.0f);
	return Bordes;
}

AObstaculos* ABuilderNivelMediano::ConstruirObstaculos()
{
	AObstaculos* Obstaculos = GetWorld()->SpawnActor<AObstaculos>(AObstaculos::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Obstaculos->AsignarTamano(50.0f, 50.0f);
	return Obstaculos;
}
