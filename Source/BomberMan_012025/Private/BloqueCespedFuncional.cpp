// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueCespedFuncional.h"

void ABloqueCespedFuncional::BeginPlay() {
	Super::BeginPlay();
	FVector old_pos = GetActorLocation();
	FVector new_pos = FVector(old_pos.X, old_pos.Y, -99.0f);
	SetActorLocation(new_pos);
}