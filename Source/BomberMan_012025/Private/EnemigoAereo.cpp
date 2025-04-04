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
}