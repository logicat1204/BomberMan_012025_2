// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMaderaFuncional.h"

void ABloqueMaderaFuncional::BeginPlay() {
	Super::BeginPlay();

	posicion_anterior = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		ControladorTiempo,
		this,
		&ABloqueMaderaFuncional::mover_bloque,
		3.0f,
		true);
}
