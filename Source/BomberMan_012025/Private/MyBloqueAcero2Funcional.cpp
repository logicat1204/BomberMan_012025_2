// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBloqueAcero2Funcional.h"

void AMyBloqueAcero2Funcional::BeginPlay() {
	Super::BeginPlay();
	
	posicion_antigua = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		TimerBloqueAcero,
		this,
		&AMyBloqueAcero2Funcional::mover_bloque_a,
		4.0f,
		true);
	
}