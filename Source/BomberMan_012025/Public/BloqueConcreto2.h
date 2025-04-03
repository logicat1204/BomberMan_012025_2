// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueConcreto2.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueConcreto2 : public ABloque
{
	GENERATED_BODY()
	
public:
	ABloqueConcreto2();
	void BeginPlay();
	FTimerHandle CambioTamano;
	void cambio_tamano();
	FVector tamano_antiguo;
	int32 cont_cambios=0;
};
