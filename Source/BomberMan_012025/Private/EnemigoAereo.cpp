// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"

AEnemigoAereo::AEnemigoAereo() {
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MallaEnAereo(TEXT("/Script/Engine.SkeletalMesh'/Game/Batron/Meshes/SK_Batron.SK_Batron'"));
	if (MallaEnAereo.Succeeded()) {
		MallaEnemigo->SetSkeletalMesh(MallaEnAereo.Object);
	}
}

void AEnemigoAereo::Tick(float DeltaTime) {
	Volar();
	int32 mov_aleatorio_aereo = FMath::RandRange(1, 4);
	switch (mov_aleatorio_aereo) {
	case 1:
		MoverAdelante(1.0f);
	case 2:
		MoverDetras(1.0f);
	case 3:
		MoverDerecha(1.0f);
	case 4:
		MoverIzquierda(1.0f);
	}
}