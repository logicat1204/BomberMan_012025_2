// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/AbstractFactory/FabricaBloquesNormales.h"

AActor* AFabricaBloquesNormales::ColocarBloque(FString tipoBloque, FVector ubicacion) 
{
	if (tipoBloque.Equals("Madera")) {
		return GetWorld()->SpawnActor<AAF_BloqueAcero>(AAF_BloqueAcero::StaticClass(), ubicacion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Acero")) {
		return GetWorld()->SpawnActor<AAF_BloqueMadera>(AAF_BloqueMadera::StaticClass(), ubicacion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else return nullptr;
}