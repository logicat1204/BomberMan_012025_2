// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "P4_Parcial.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AP4_Parcial : public ABloque
{
	GENERATED_BODY()
public:
	AP4_Parcial();
	float mov_time=4.0f;
	int mov;
	FTimerHandle TimerNewMov;
	FTimerHandle TimerOldMov;
	FVector old_pos;
	virtual void BeginPlay() override;
	void new_mov();
	void old_mov();
};
