// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/Builder/Bordes.h"
#include "Patterns/Builder/Obstaculos.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nivel.generated.h"

UCLASS()
class BOMBERMAN_012025_API ANivel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANivel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	ABordes* Bordes;
	AObstaculos* Obstaculos;
	FVector location;
	void Colocar();
};
