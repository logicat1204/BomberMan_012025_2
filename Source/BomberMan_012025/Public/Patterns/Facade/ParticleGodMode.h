// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleGodMode.generated.h"

UCLASS()
class BOMBERMAN_012025_API AParticleGodMode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticleGodMode();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UParticleSystem* PartycleGodMode;
	UParticleSystemComponent* ParticleInstance=nullptr;
	APawn* MyPlayer;
	FTimerHandle THDuracion;
	float duracion_particle=5.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DestroyParticle();
};
