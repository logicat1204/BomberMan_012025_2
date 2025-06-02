// Fill out your copyright notice in the Description page of Project Settings.
#include "SegundoParcial/BuilderEjercitoEnemigos.h"
#include "SegundoParcial/Ejercito.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorEjercitos.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADirectorEjercitos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorEjercitos();
	TArray<FVector> EspaciosColocar;
	IBuilderEjercitoEnemigos* Builder;
	AEjercito* Ejercito;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetEspaciosColocarEnemigos(TArray<FVector> EspaciosC);
	void SetBuilder(IBuilderEjercitoEnemigos* NuevoBuilder);
	void CrearEjercito();
};
