// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Builder/Obstaculos.h"

// Sets default values
AObstaculos::AObstaculos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstaculos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstaculos::ColocarObs()
{
	int32 tamano = (largo - 1) * (ancho - 1); // área interior
	int32 cant_obs = FMath::RandRange(1, tamano);

	for (int32 i = 1; i < largo; i++) {
		for (int32 j = 1; j < ancho; j++) {
			if (cant_obs <= 0) return;

			bool set = FMath::RandBool();
			if (set) {
				FVector posicion = ubi_colocar + FVector(i * 100.0f, j * 100.0f, 0.0f);
				GetWorld()->SpawnActor<ABloqueMadera>(
					ABloqueMadera::StaticClass(),
					posicion,
					FRotator::ZeroRotator
				);
				cant_obs--; // reducir contador
			}
		}
	}
}

void AObstaculos::AsignarTamano(int32 largo_nuevo, int32 ancho_nuevo)
{
	largo = largo_nuevo;
	ancho = ancho_nuevo;
}
