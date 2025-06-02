// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Prototype.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPrototype : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IPrototype
{
	GENERATED_BODY()
public:
	int health;
	int damage;
	FString name;
public:
	virtual AActor* Clonar() PURE_VIRTUAL(IPrototype::Clonar, return nullptr;);
};
