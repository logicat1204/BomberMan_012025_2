// Fill out your copyright notice in the Description page of Project Settings.
#include "Bloque.h"
#include "PrimerParcial/PuertaPortal.h"
#include "Enemigo.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NivelBomberman.generated.h"

UCLASS()
class BOMBERMAN_012025_API ANivelBomberman : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANivelBomberman();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<ABloque*> Terreno;
	TArray<ABloque*> Muros;
	TArray<FVector> EspaciosEnBlanco;
	TArray<APuertaPortal*> Puertas;
	TArray<ABloque*> Obstaculos;
	TArray<AEnemigo*> Enemigos;

};
