// Fill out your copyright notice in the Description page of Project Settings.
#include "Bloque.h"
#include "Patterns/AbstractFactory/AF_BloqueAcero.h"
#include "Patterns/AbstractFactory/AF_BloqueMadera.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbstractFactory.generated.h"

UCLASS()
class BOMBERMAN_012025_API AAbstractFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/** Método abstracto con parámetros */
	UFUNCTION(BlueprintCallable, Category = "Factories")
	virtual AActor* ColocarBloque(FString tipoBloque,FVector ubicacion) PURE_VIRTUAL(AAbstractFactory::ColocarBloque, return nullptr;);
};
