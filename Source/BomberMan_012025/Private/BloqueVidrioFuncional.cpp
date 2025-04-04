// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueVidrioFuncional.h"

void ABloqueVidrioFuncional::BeginPlay() {
	Super::BeginPlay();
	/*
	posicion_anterior = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		ControladorTiempoVidrio,
		this,
		&ABloqueVidrioFuncional::mover_bloque,
		1.0f,
		true);
}

void ABloqueVidrioFuncional::mover_bloque()
{
	contadorTicks++;
	FVector posicion_actual = GetActorLocation();
	posicion_actual.X += mov_adelante;
	FVector posicion_nueva = posicion_actual;
	SetActorLocation(posicion_nueva);
	if (contadorTicks == 2) {
		SetActorLocation(posicion_anterior);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Regresa a su posicion"));
		contadorTicks = 0;
	}
}
*/
}