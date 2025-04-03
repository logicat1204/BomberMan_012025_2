// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto2.h"

ABloqueConcreto2::ABloqueConcreto2() {

	PrimaryActorTick.bCanEverTick = false;


	static ConstructorHelpers::FObjectFinder<UMaterial>AssetConcreto(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Concrete_Tiles.M_Concrete_Tiles'"));
	if (AssetConcreto.Succeeded()) {
		MallaBloque->SetMaterial(0, AssetConcreto.Object);
	}
}

void ABloqueConcreto2::BeginPlay() {
	Super::BeginPlay();
	/*
	tamano_antiguo = GetActorScale3D();
	GetWorldTimerManager().SetTimer(CambioTamano,
		this,
		&ABloqueConcreto2::cambio_tamano,
		4.0f,
		true
	);
	*/
}

void ABloqueConcreto2::cambio_tamano() {
	cont_cambios++;
	FVector actual_pos = GetActorScale3D();
	FVector nueva_pos = FVector(actual_pos.X*2,actual_pos.Y*2,actual_pos.Z*2);
	SetActorScale3D(nueva_pos);
	if (cont_cambios == 2) {
		SetActorScale3D(tamano_antiguo);
		cont_cambios = 0;
	}
}