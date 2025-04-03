// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueMadera.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueMadera : public ABloque
{
	GENERATED_BODY()

public:
	void mover_bloque();
	void destruirse();
	void BeginPlay();
	void Tick(float DeltaTime);
	float mov_adelante=100.0f;
	FVector posicion_anterior;
	FTimerHandle ControladorTiempo;
	int32 contadorTicks;

	FTimerHandle Destruccion;
	int32 contadorDestruir=0;
	ABloqueMadera();


public:
	bool PuedeDestruirse;

};
