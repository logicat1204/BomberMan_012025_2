// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"



ABloqueMadera::ABloqueMadera(){

	static ConstructorHelpers::FObjectFinder<UMaterial>AssetMadera(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	if (AssetMadera.Succeeded()) {
		MallaBloque->SetMaterial(0, AssetMadera.Object);
	}


	PrimaryActorTick.bCanEverTick = false;


}



void ABloqueMadera::mover_bloque()
{
	contadorTicks++;
	FVector posicion_actual = GetActorLocation();
	posicion_actual.X += mov_adelante;
	FVector posicion_nueva = posicion_actual;
	SetActorLocation(posicion_nueva);
	if (contadorTicks == 5) {
		SetActorLocation(posicion_anterior);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Regresa a su posicion"));
	}
}

void ABloqueMadera::destruirse()
{
	if (this != nullptr) {
		this->Destroy();
	}
}

void ABloqueMadera::BeginPlay() {
	Super::BeginPlay();
	/*GetWorldTimerManager().SetTimer(
		Destruccion,
		this,
		&ABloqueMadera::destruirse,
		7.0f,
		true
	);

	*/


	/*
	posicion_anterior = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		ControladorTiempo, 
		this, 
		&ABloqueMadera::mover_bloque, 
		3.0f, 
		true);
		*/
}


void ABloqueMadera::Tick(float DeltaTime) {
	

	Super::Tick(DeltaTime);
}

