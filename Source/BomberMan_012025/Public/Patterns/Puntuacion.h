// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puntuacion.generated.h"

UCLASS()
class BOMBERMAN_012025_API APuntuacion : public AActor
{
	GENERATED_BODY()
	UPROPERTY()
	APuntuacion* Instancia;
	
public:	
	// Sets default values for this actor's properties
	APuntuacion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int32 puntuacion_tot=0;
	FTimerHandle TH_show_puntuacion;
	void show_puntuacion();
};
