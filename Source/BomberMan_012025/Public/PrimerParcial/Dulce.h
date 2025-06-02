// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dulce.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADulce : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADulce();

	UStaticMeshComponent* MallaDulce;
private:
	//inicia en la posicion 0
	int32 nroDePosicion=0;
	APawn* MiJugador;
public:
	int32 nro_max_pos = 4;
	TArray<FVector> posiciones_tp;
	float tiempo_tp=15.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void next();
	void previous();
	void comer_dulce();
	void asignar_puntuacion();
public:
	//Timers
	FTimerHandle TH_next, TH_previous;
	int32 asig_pt=0;

};
