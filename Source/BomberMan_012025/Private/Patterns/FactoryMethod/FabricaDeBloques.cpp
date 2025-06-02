// Fill out your copyright notice in the Description page of Project Settings.

#include "Patterns/FactoryMethod/FabricaDeBloques.h"
#include "BloqueAcero2.h"
#include "BloqueAgua.h"
#include "BloqueArena.h"
#include "BloqueCesped.h"
#include "BloqueConcreto2.h"
#include "BloqueLadrillo2.h"
#include "BloqueMadera.h"
#include "BloqueOro.h"
#include "BloqueRoca.h"
#include "BloqueVidrio.h"

//Definimos la variable estatica del TArray
TArray<ABloque*> AFabricaDeBloques::aBloques;

// Sets default values
AFabricaDeBloques::AFabricaDeBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaDeBloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaDeBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABloque* AFabricaDeBloques::CrearBloque(TipoBloque tipo, FVector posicionColocar)
{
	if (tipo==Madera) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueMadera::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Concreto) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueConcreto2::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Arena) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueArena::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Cesped) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueCesped::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Acero) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueAcero2::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Agua) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueAgua::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Ladrillo) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueLadrillo2::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Oro) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueOro::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Roca) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueRoca::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else if (tipo == Vidrio) {
		BloqueCreado = GetWorld()->SpawnActor<ABloque>(ABloqueVidrio::StaticClass(), posicionColocar, FRotator::ZeroRotator);
	}
	else {
		return nullptr;
	}
	aBloques.Add(BloqueCreado);
	return BloqueCreado;
}

TArray<ABloque*> AFabricaDeBloques::GetBloques()
{
	return TArray<ABloque*>(aBloques);
}

