// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AF_BloqueMadera.generated.h"

UCLASS()
class BOMBERMAN_012025_API AAF_BloqueMadera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAF_BloqueMadera();
	AAF_BloqueMadera(bool esMagico);
	UStaticMeshComponent* MallaBloqueMadera;


private:
	bool Magico; // Estado del bloque
	bool bEsFantasma = false;
	float TiempoFantasma = 0.0f; // Temporizador
	float DuracionFantasma = 3.0f; // Tiempo que permanece intangible
	float IntervaloFantasma = 5.0f; // Tiempo entre cada fase fantasma

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetMagico(bool esMagico) { Magico = esMagico; }
};
