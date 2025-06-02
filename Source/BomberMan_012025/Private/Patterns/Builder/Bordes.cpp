// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Builder/Bordes.h"

// Sets default values
ABordes::ABordes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABordes::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABordes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABordes::ColocarB()
{
	for (float i = 0; i <= largo; i++) {
		for (float j = 0; j <= ancho; j++) {
			// Calcula posición una sola vez
			FVector posicion = ubi_colocar + FVector(i * 100.0f, j * 100.0f, 0.0f);

			// Bordes horizontales (arriba y abajo)
			if (i == 0 || i == largo) {
				GetWorld()->SpawnActor<ABloqueAcero2>(
					ABloqueAcero2::StaticClass(),
					posicion,
					FRotator::ZeroRotator
				);
			}
			// Bordes verticales (izquierda y derecha), excluyendo esquinas ya construidas
			else if (j == 0 || j == ancho) {
				GetWorld()->SpawnActor<ABloqueAcero2>(
					ABloqueAcero2::StaticClass(),
					posicion,
					FRotator::ZeroRotator
				);
			}
		}
	}
}

void ABordes::AsignarTamano(int32 largo_nuevo, int32 ancho_nuevo)
{
	largo = largo_nuevo;
	ancho = ancho_nuevo;
}

