// Fill out your copyright notice in the Description page of Project Settings.
#include "BomberMan_012025/BomberMan_012025Character.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpeedBoost.generated.h"

UCLASS()
class BOMBERMAN_012025_API ASpeedBoost : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeedBoost();
	ACharacter* MyPlayer;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float default_speed = 100.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void IncreasePlayerSpeed();
	void ResetPlayerSpeed();
private:
	FTimerHandle THDefaultSpeed;
	UPROPERTY(EditAnywhere)
	float set_default_time=5.0f;
};
