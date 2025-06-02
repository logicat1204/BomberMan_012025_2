// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/BuilderNuevo/I_BuilderNivel.h"
#include "Patterns/BuilderNuevo/BuilderNivelAleatorio.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorNiveles.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADirectorNiveles : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ADirectorNiveles();
	ABuilderNivelAleatorio* Builder;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	FVector posColocar1;
	UPROPERTY(EditAnywhere)
	FVector posColocar2;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetBuilder(ABuilderNivelAleatorio* BuilderNuevo);
	void ConstruirNivel();
};
