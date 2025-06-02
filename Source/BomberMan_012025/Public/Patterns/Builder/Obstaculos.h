// Fill out your copyright notice in the Description page of Project Settings.
#include "BloqueMadera.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculos.generated.h"

UCLASS()
class BOMBERMAN_012025_API AObstaculos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstaculos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int32 largo;
	int32 ancho;
	FVector ubi_colocar;
	void ColocarObs();
	void AsignarTamano(int32 largo_nuevo, int32 ancho_nuevo);
};
