// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BloqueOro.h"
#include "BloqueOroFuncional.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueOroFuncional : public ABloqueOro
{
	GENERATED_BODY()
	void rotar_bloque();
	void BeginPlay();
	FTimerHandle TiempoRotar;
	int32 veces_rotado;
	int32 rotacion = 30.0f;
};
