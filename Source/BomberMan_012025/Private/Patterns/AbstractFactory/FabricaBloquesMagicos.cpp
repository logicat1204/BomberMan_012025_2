// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/AbstractFactory/FabricaBloquesMagicos.h"
AAF_BloqueAcero* BloqueColocado;
AAF_BloqueMadera* BloqueMColocado;
AActor* AFabricaBloquesMagicos::ColocarBloque(FString tipoBloque, FVector ubicacion)
{
	if (tipoBloque.Equals("Madera")) {
		BloqueColocado = GetWorld()->SpawnActor<AAF_BloqueAcero>(AAF_BloqueAcero::StaticClass(), ubicacion, FRotator(0.0f, 0.0f, 0.0f));
		if (BloqueColocado) 
		{
			BloqueColocado->SetMagico(true);
			return BloqueColocado;
		}
		else return nullptr;
	}
	else if (tipoBloque.Equals("Acero")) 
	{
		BloqueMColocado = GetWorld()->SpawnActor<AAF_BloqueMadera>(AAF_BloqueMadera::StaticClass(), ubicacion, FRotator(0.0f, 0.0f, 0.0f));
		if (BloqueMColocado)
		{
			BloqueMColocado->SetMagico(true);
			return BloqueMColocado;

		}
		else return nullptr;
	}
	else return nullptr;
}