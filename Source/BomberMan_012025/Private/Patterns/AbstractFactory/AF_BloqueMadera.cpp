// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/AbstractFactory/AF_BloqueMadera.h"

// Sets default values
AAF_BloqueMadera::AAF_BloqueMadera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaBloqueMadera = CreateDefaultSubobject<UStaticMeshComponent>("MallaBloqueMadera");
	ConstructorHelpers::FObjectFinder<UStaticMesh> FormaBloque(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (FormaBloque.Succeeded())
	{
		MallaBloqueMadera->SetStaticMesh(FormaBloque.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial> MaterialAcero(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Pine.M_Wood_Pine'"));
	if (MaterialAcero.Succeeded())
	{
		MallaBloqueMadera->SetMaterial(0, MaterialAcero.Object);
	}
}

AAF_BloqueMadera::AAF_BloqueMadera(bool esMagico)
{
	SetMagico(esMagico);
}

// Called when the game starts or when spawned
void AAF_BloqueMadera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAF_BloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Actualizar temporizador
    TiempoFantasma += DeltaTime;

    if (Magico)
    {
        if (bEsFantasma)
        {
            // Si ha pasado el tiempo de ser fantasma, vuelve a ser sólido
            if (TiempoFantasma >= DuracionFantasma)
            {
                SetActorEnableCollision(true);
                MallaBloqueMadera->SetVisibility(true); // Vuelve a ser visible
                bEsFantasma = false;
                TiempoFantasma = 0.0f;
            }
        }
        else
        {
            // Si ha pasado el intervalo, se vuelve fantasma
            if (TiempoFantasma >= IntervaloFantasma)
            {
                SetActorEnableCollision(false);
                MallaBloqueMadera->SetVisibility(false); // Se vuelve invisible
                bEsFantasma = true;
                TiempoFantasma = 0.0f;
            }
        }

    }

}

