// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigo : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigo();

	USkeletalMeshComponent* MallaEnemigo;
	UStaticMeshComponent* MallaAltEnemigo;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void MoverAdelante(float value);
	void MoverDetras(float value);
	void MoverDerecha(float value);
	void MoverIzquierda(float value);
	void Volar();
	int32 vuelo;
};
