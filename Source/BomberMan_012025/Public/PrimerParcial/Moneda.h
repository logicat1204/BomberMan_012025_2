// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BomberMan_012025/BomberMan_012025GameMode.h"
#include "Moneda.generated.h"

UCLASS()
class BOMBERMAN_012025_API AMoneda : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoneda();
	UStaticMeshComponent* MallaMoneda;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int32 ciclos = 1;
	float velocidadRotacion=1.0f;
	//Cambiar eje z en angulo maximo rotacion
	FRotator AnguloMaximoRotacion = FRotator(90.0f,0.0f,360.0f);
	FRotator nueva_rot=FRotator(90.0f,0.0f,0.0f);
	int32 sentido_rotacion = 1;
	bool ciclo_completo = false;
	int32 cont_sub_ciclo = 0;
	int32 pos_rot;
public:
	//Timers
	FTimerHandle TH_rotar;
	//Guardar gamemode para extraer de ahi los espacios en blanco guardados en un TArray
	ABomberMan_012025GameMode* GameModeActual;
public:
	void rotar();
};
