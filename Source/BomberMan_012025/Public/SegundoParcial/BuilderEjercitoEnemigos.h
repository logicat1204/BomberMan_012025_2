// Fill out your copyright notice in the Description page of Project Settings.
#include "SegundoParcial/Ejercito.h"
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuilderEjercitoEnemigos.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuilderEjercitoEnemigos : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IBuilderEjercitoEnemigos
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:
	virtual void AsignarEspaciosEnBlanco(TArray<FVector> Espacios) = 0;
	virtual void CrearEnemigosNormales(int32 cant_enemigos) = 0;
	virtual void CrearEnemigosVoladores(int32 cant_enemigos) = 0;
	virtual void CrearComandante() = 0;
	virtual class AEjercito* ObtenerEjercito() = 0;
};
