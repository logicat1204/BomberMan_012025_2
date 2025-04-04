// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueOroFuncional.h"

void ABloqueOroFuncional::rotar_bloque() {
	FRotator nueva_rotacion(0.0f, rotacion, 0.0f);
	SetActorRotation(nueva_rotacion);
	rotacion += 30.0f;
	veces_rotado++;
	if (veces_rotado == 5) {
		rotacion = 30;
	}
}

void ABloqueOroFuncional::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		TiempoRotar,
		this,
		&ABloqueOroFuncional::rotar_bloque,
		3.0f,
		true
	);

}