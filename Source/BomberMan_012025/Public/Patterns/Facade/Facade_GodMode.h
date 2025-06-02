// Fill out your copyright notice in the Description page of Project Settings.
#include "Patterns/Facade/BombTurboMode.h"
#include "Patterns/Facade/ParticleGodMode.h"
#include "Patterns/Facade/SpeedBoost.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Facade_GodMode.generated.h"

UCLASS()
class BOMBERMAN_012025_API AFacade_GodMode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacade_GodMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	float duration_godmode=5.0f;
	ABombTurboMode* BombTurbo;
	AParticleGodMode* Particles;
	ASpeedBoost* SpeedBoost;
	FTimerHandle THDuration;
	UPROPERTY(EditAnywhere)
	float duration=8.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Off();
};
