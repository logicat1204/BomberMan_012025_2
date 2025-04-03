// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueAcero2.h"

ABloqueAcero2::ABloqueAcero2(){

	PrimaryActorTick.bCanEverTick = false;


	static ConstructorHelpers::FObjectFinder<UMaterial>AssetAcero(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (AssetAcero.Succeeded()) {
		MallaBloque->SetMaterial(0, AssetAcero.Object);
	}
}

void ABloqueAcero2::BeginPlay() {
	Super::BeginPlay();
	/*
	posicion_antigua = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		TimerBloqueAcero,
		this,
		&ABloqueAcero2::mover_bloque_a(funcion),
		4.0f,
		true
	);
	*/
	
}

void ABloqueAcero2::Tick(float DeltaTime) {
	
}

void ABloqueAcero2::mover_bloque_a()
{
	cont_arriba++;
	FVector posicion_actual = GetActorLocation();
	FVector posicion_nueva=posicion_actual;
	posicion_nueva.Z += 100.0f*Direccion;
	SetActorLocation(posicion_nueva);
	if (cont_arriba == 5) {
		//SetActorLocation(posicion_antigua);
		Direccion *= -1;
		cont_arriba = 0;
	}
}
