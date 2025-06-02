// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AF_BloqueAcero.generated.h"

UCLASS()
class BOMBERMAN_012025_API AAF_BloqueAcero : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAF_BloqueAcero();
	AAF_BloqueAcero(bool esMagico);
	UStaticMeshComponent* MallaBloqueAcero;
private:
	bool Magico;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetMagico(bool esMagico) { Magico = esMagico; }
};
