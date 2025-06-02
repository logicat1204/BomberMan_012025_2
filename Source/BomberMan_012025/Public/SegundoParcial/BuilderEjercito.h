// Fill out your copyright notice in the Description page of Project Settings.
#include "SegundoParcial/BuilderEjercitoEnemigos.h"
#include "SegundoParcial/Ejercito.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderEjercito.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABuilderEjercito : public AActor, public IBuilderEjercitoEnemigos
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderEjercito();
	AEjercito* Ejercito;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<FVector> EspaciosDisponibles;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AsignarEspaciosEnBlanco(TArray<FVector> Espacios) override;
	virtual void CrearEnemigosNormales(int32 cant_enemigos) override;
	virtual void CrearEnemigosVoladores(int32 cant_enemigos) override;
	virtual void CrearComandante() override;
	virtual class AEjercito* ObtenerEjercito() override;
};
