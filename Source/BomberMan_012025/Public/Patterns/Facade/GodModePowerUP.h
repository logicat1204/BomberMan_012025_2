// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GodModePowerUP.generated.h"

UCLASS()
class BOMBERMAN_012025_API AGodModePowerUP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGodModePowerUP();
	UStaticMeshComponent* MallaGodMode;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	APawn* Player;
	float Dist_player;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void execute_god_mode();
};
