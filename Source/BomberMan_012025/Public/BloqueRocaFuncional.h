// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BloqueRoca.h"
#include "BloqueRocaFuncional.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueRocaFuncional : public ABloqueRoca
{
	GENERATED_BODY()
	void BeginPlay();
	void MoverAdelante(float value);
	void MoverDetras(float value);

	/*
	void BeginPlay();
	void mover_bloque();
	FVector posicion_anterior;
	FTimerHandle ControladorTiempo;
	float mov_adelante = 100.0f;
	FVector posicion_anterior;
	FTimerHandle ControladorTiempo;
	int32 contadorTicks;
	*/
	void MoverDerecha(float value);
	void MoverIzquierda(float value);
	void MoverArriba(float value);
	void MoverAbajo(float value);
	void movimiento_aleatorio();
	FTimerHandle MovimientoTimer;
};
