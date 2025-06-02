
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Comandante.generated.h"

UCLASS()
class BOMBERMAN_012025_API AComandante : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComandante();
	USkeletalMeshComponent* MallaCOM;
	TArray<FVector> CPosicionesMover;
	FTimerHandle THComMov;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MoverCOM();
};
