// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Patterns/Prototype/Prototype.h"
#include "EnemigoClonable.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigoClonable : public AActor, public IPrototype
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigoClonable();
	USkeletalMeshComponent* EnemyMesh;
	bool bIsGrowing;
	float ScaleSpeed=0.5;
	float MaxScale=200.0f,MinScale=100.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	int health = FMath::RandRange(1, 100);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual AActor* Clonar() override;
	void ClonarActor();
	void ChangeSize();
};
