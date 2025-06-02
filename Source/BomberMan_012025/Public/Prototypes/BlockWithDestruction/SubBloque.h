// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SubBloque.generated.h"

UCLASS()
class BOMBERMAN_012025_API ASubBloque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASubBloque();

	// Llamado desde ABloque
	void ActivarDesvanecimiento();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComp;

	bool bDestruirSubBloque;
	float VelocidadEscala;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
