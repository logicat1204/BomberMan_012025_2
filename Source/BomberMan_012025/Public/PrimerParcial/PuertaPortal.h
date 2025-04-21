// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuertaPortal.generated.h"

class ABomberMan_012025GameMode;

UCLASS()

class BOMBERMAN_012025_API APuertaPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuertaPortal();

	UStaticMeshComponent* MallaPuerta;

	bool bPuedeTeletransportar;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool CanBeBaseForCharacter(APawn* APawn) const override;
};
