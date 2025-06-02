// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Patterns/Builder/BuilderNivel.h"
#include "BuilderNivelGrande.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABuilderNivelGrande : public ABuilderNivel
{
	GENERATED_BODY()
public:
	virtual ABordes* ConstruirBordes() override;
	virtual AObstaculos* ConstruirObstaculos() override;

};
