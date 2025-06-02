// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemigoVolador.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigoVolador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigoVolador();
	USkeletalMeshComponent* MallaEV;
	bool izq_der;
	FVector Pos_vieja;
	int32 mov_actual=0;
	UPROPERTY(EditAnywhere)
	int32 cant_movimientos=5;
	FTimerHandle THMovimientoVolador;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Moverse();
};
