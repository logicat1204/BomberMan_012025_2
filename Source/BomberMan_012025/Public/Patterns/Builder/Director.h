// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/Builder/Nivel.h"
#include "Patterns/Builder/BuilderNivel.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Director.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirector();
	ANivel* NivelPersonalizado;
	ABuilderNivel* Builder;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AsignarBuilder(ABuilderNivel* nuevo_builder);
	void CrearNivel(FVector coor_colocar);
};
