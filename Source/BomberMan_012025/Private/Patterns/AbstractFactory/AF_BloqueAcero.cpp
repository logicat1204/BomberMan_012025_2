// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/AbstractFactory/AF_BloqueAcero.h"

// Sets default values
AAF_BloqueAcero::AAF_BloqueAcero()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaBloqueAcero = CreateDefaultSubobject<UStaticMeshComponent>("MallaBloqueAcero");
	ConstructorHelpers::FObjectFinder<UStaticMesh> FormaBloque(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (FormaBloque.Succeeded())
	{
		MallaBloqueAcero->SetStaticMesh(FormaBloque.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial> MaterialAcero(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Brushed_Nickel.M_Metal_Brushed_Nickel'"));
	if (MaterialAcero.Succeeded())
	{
		MallaBloqueAcero->SetMaterial(0, MaterialAcero.Object);
	}
}

AAF_BloqueAcero::AAF_BloqueAcero(bool esMagico)
{
	SetMagico(esMagico);
}

// Called when the game starts or when spawned
void AAF_BloqueAcero::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAF_BloqueAcero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Magico)
	{
		// Parámetros de movimiento
		float rangoVuelo = 5.0f;
		float velocidadOscilacion = 0.2f; // Ajusta la velocidad del movimiento
		float tiempo = GetWorld()->GetTimeSeconds();

		// Calcula la nueva posición usando una función senoidal
		FVector pos_vieja = GetActorLocation();
		float nuevaAltura = pos_vieja.Z + rangoVuelo * FMath::Sin(velocidadOscilacion * tiempo);

		// Establece la nueva posición
		SetActorLocation(FVector(pos_vieja.X, pos_vieja.Y, nuevaAltura));
	}

}