// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueRoca.h"

ABloqueRoca::ABloqueRoca() {

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Basalt.M_Rock_Basalt'"));
	if (Material.Succeeded())
	{
		MallaBloque->SetMaterial(0, Material.Object);
	}
}