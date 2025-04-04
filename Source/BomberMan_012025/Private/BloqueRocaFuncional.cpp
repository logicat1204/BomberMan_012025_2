// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueRocaFuncional.h"
/*
void ABloqueRocaFuncional::BeginPlay() {
	Super::BeginPlay();

	posicion_anterior = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		ControladorTiempo,
		this,
		&ABloqueRocaFuncional::mover_bloque,
		0.5f,
		true);
}

void ABloqueRocaFuncional::mover_bloque()
{
	contadorTicks++;
	FVector posicion_actual = GetActorLocation();
	posicion_actual.X += mov_adelante;
	FVector posicion_nueva = posicion_actual;
	SetActorLocation(posicion_nueva);
	if (contadorTicks == 3) {
		SetActorLocation(posicion_anterior);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Regresa a su posicion"));
		contadorTicks = 0;
	}
}
*/