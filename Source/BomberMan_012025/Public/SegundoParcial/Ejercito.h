// Fill out your copyright notice in the Description page of Project Settings.
#include "SegundoParcial/EnemigoNormal.h"
#include "SegundoParcial/EnemigoVolador.h"
#include "SegundoParcial/Comandante.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ejercito.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEjercito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEjercito();
	TArray<AEnemigoNormal*> EnemigosNormales;
	TArray<AEnemigoVolador*> EnemigosVoladores;
	AComandante* Comandante;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
