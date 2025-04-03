// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBloqueLadrillo2Funcional.h"

void AMyBloqueLadrillo2Funcional::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(
		TiempoRotar,
		this,
		&AMyBloqueLadrillo2Funcional::rotar_bloque,
		3.0f,
		true
	);
	
}