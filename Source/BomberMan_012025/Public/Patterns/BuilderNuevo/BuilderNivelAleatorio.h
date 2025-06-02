// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/BuilderNuevo/I_BuilderNivel.h"
#include "Patterns/BuilderNuevo/NivelBomberman.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderNivelAleatorio.generated.h"


UCLASS()
class BOMBERMAN_012025_API ABuilderNivelAleatorio : public AActor , public II_BuilderNivel
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ABuilderNivelAleatorio();
	ANivelBomberman* ANivelBomb;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector LugarConstruccionInicio;
	FVector LugarConstruccionFin;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SeleccionarLugarConstruccion(FVector pos1, FVector pos2) override;
	virtual void CrearTerreno() override ;
	virtual void CrearMuros() override;
	virtual void CrearPuertas(int32 cant_puertas) override;
	virtual void CrearObstaculos(int32 cant_obstaculos) override;
	void DistribuirObstaculosUniforme(int32 CantidadObstaculos);
	virtual void CrearEscondites(int32 cant_escondites) override;
	virtual void ColocarEnemigos(int32 cant_enemigos) override;
	virtual class ANivelBomberman* ObtenerNivel() override;
};
