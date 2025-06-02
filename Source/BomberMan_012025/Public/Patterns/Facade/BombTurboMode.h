// Fill out your copyright notice in the Description page of Project Settings.
#include "Kismet/GameplayStatics.h"
#include "BomberMan_012025/BomberMan_012025Character.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombTurboMode.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABombTurboMode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombTurboMode();
	ABomberMan_012025Character* Player;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle THNormalSetTimer;
	float time_to_normal = 5.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ResetNormal();
};
