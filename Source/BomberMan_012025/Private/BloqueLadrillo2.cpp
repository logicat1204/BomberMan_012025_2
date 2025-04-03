// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo2.h"

ABloqueLadrillo2::ABloqueLadrillo2() {

	PrimaryActorTick.bCanEverTick = false;


	static ConstructorHelpers::FObjectFinder<UMaterial>AssetLadrillo(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (AssetLadrillo.Succeeded()) {
		MallaBloque->SetMaterial(0, AssetLadrillo.Object);
	}
}

void ABloqueLadrillo2::rotar_bloque() {
	FRotator nueva_rotacion(0.0f, rotacion, 0.0f);
	SetActorRotation(nueva_rotacion);
	rotacion += 30.0f;
	veces_rotado++;
	if (veces_rotado == 5) {
		rotacion = 30;
	}
}

void ABloqueLadrillo2::BeginPlay()
{
	Super::BeginPlay();
	/*
	GetWorldTimerManager().SetTimer(
		TiempoRotar,
		this,
		&ABloqueLadrillo2::rotar_bloque,
		3.0f,
		true
	);
	*/
}

