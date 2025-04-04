// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BloqueVidrio.h"
#include "BloqueVidrioFuncional.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueVidrioFuncional : public ABloqueVidrio
{
	GENERATED_BODY()
	void BeginPlay();
	/*
	void mover_bloque();
	FVector posicion_anterior;
	FTimerHandle ControladorTiempoVidrio;
	float mov_adelante = 100.0f;
	FVector posicion_anterior;
	FTimerHandle ControladorTiempo;
	int32 contadorTicks;
	*/
};
