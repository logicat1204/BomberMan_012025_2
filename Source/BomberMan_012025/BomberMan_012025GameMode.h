// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "MyBloqueAcero2Funcional.h"
#include "MyBloqueConcreto2Funcional.h"
#include "MyBloqueLadrillo2Funcional.h"
#include "BloqueMaderaFuncional.h"
#include "BloqueAcero2.h"
#include "BloqueConcreto2.h"
#include "BloqueLadrillo2.h"
#include "BloqueMadera.h"
#include "Bloque.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberMan_012025GameMode.generated.h"

UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberMan_012025GameMode();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	FTransform LugarAparicion;
	bool bAleatorio;
	int32 cont_b_ale=0;

	bool setAleatorio = false;









	//Niveles
	TArray<TArray<int32>> Nivel1 = 
	{ 
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4},
		{4,0,0,2,0,0,0,2,2,2,2,0,0,4},
		{4,1,1,1,1,0,0,0,0,0,0,0,1,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4},
		{4,3,3,3,3,1,1,1,0,0,0,0,0,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4},
		{4,1,1,1,1,2,2,2,2,0,0,0,0,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4}
	};

	TArray<TArray<int32>> Nivel3 =
	{
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
		{4,0,0,2,0,0,0,2,2,2,2,0,0,4,0,0,0,4},
		{4,1,1,1,1,0,0,0,0,0,0,0,1,4,1,2,0,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4},
		{4,3,3,3,3,1,1,1,0,0,0,0,0,4,1,0,3,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0,4},
		{4,1,1,1,1,2,2,2,2,0,0,0,0,4,2,3,0,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,2,4},
		{4,0,0,0,0,3,3,1,0,0,2,2,0,0,0,0,0,4},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,0,4},
		{4,0,2,2,3,1,0,0,2,0,0,1,0,4,0,2,3,4},
		{4,1,2,3,4,0,0,0,0,4,0,0,0,1,0,0,0,4},
		{4,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,4},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
	};

	void GenerarNivel(FVector locacionGenerar,TArray<TArray<int32>> ArregloNivel);
};



