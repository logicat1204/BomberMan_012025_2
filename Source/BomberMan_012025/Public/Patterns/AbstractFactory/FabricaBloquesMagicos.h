// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Patterns/AbstractFactory/AbstractFactory.h"
#include "FabricaBloquesMagicos.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AFabricaBloquesMagicos : public AAbstractFactory
{
	GENERATED_BODY()
	
public:
	virtual AActor* ColocarBloque(FString tipoBloque, FVector ubicacion);
};
