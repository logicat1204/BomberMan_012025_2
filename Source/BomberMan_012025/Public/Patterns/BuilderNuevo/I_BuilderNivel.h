// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_BuilderNivel.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UI_BuilderNivel : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API II_BuilderNivel
{
	GENERATED_BODY()
	class ANivel;
	virtual void SeleccionarLugarConstruccion(FVector pos1,FVector pos2) = 0;
	virtual void CrearTerreno() = 0;
	virtual void CrearMuros() = 0;
	virtual void CrearPuertas(int32 cant_puertas) = 0;
	virtual void CrearObstaculos(int32 cant_obstaculos) = 0;
	virtual void CrearEscondites(int32 cant_escondites) = 0;
	virtual void ColocarEnemigos(int32 cant_enemigos) = 0;
	//se usa forward declaration (declaracion adelantada) para mostrar que la funcion devolvera una clase que sea el nivel
	virtual class ANivelBomberman* ObtenerNivel() = 0;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
