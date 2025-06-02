// Fill out your copyright notice in the Description page of Project Settings.
#include "BloqueAcero2.h"
#include "BloqueMadera.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bordes.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABordes : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABordes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int32 largo;
	int32 ancho;
	FVector ubi_colocar;
	void ColocarB();
	void AsignarTamano(int32 largo_nuevo, int32 ancho_nuevo);
};
