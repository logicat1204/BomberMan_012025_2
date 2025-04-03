// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueAcero2.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueAcero2 : public ABloque
{
	GENERATED_BODY()
	
public:
	ABloqueAcero2();
	void BeginPlay();
	void Tick(float DeltaTime);
	FTimerHandle TimerBloqueAcero;
	void mover_bloque_a();
	FVector posicion_antigua;
	int32 cont_arriba;
	int32 Direccion = 1;
};
