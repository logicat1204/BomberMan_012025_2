// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoSubterraneo.h"



AEnemigoSubterraneo::AEnemigoSubterraneo() {
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>AssetEnTerrestre(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	if (AssetEnTerrestre.Succeeded()) {
		MallaEnemigo->SetSkeletalMesh(AssetEnTerrestre.Object);
	}
}