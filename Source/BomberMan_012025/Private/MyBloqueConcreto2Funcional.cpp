// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBloqueConcreto2Funcional.h"

void AMyBloqueConcreto2Funcional::BeginPlay() {
	Super::BeginPlay();
	tamano_antiguo = GetActorScale3D();
	GetWorldTimerManager().SetTimer(CambioTamano,
		this,
		&ABloqueConcreto2::cambio_tamano,
		4.0f,
		true);
}