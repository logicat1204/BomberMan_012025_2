// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueLadrillo2.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueLadrillo2 : public ABloque
{
	GENERATED_BODY()

public:
	ABloqueLadrillo2();
	void rotar_bloque();
	void BeginPlay();
	FTimerHandle TiempoRotar;
	int32 veces_rotado;
	int32 rotacion = 30.0f;
	;
};
