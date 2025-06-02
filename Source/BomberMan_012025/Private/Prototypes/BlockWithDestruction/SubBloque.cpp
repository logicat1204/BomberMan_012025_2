// Fill out your copyright notice in the Description page of Project Settings.


#include "Prototypes/BlockWithDestruction/SubBloque.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
ASubBloque::ASubBloque()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    RootComponent = MeshComp;

    // Usa el cubo por defecto
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube"));
    if (CubeMesh.Succeeded())
    {
        MeshComp->SetStaticMesh(CubeMesh.Object);
    }

    MeshComp->SetSimulatePhysics(true);
    MeshComp->SetWorldScale3D(FVector(0.3f)); // fragmentos más pequeños


    bDestruirSubBloque = false;
    VelocidadEscala = 0.3f; // tamaño inicial
}

// Called when the game starts or when spawned
void ASubBloque::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASubBloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (bDestruirSubBloque)
    {
        VelocidadEscala -= DeltaTime * 0.15f; // reduce escala cada frame

        if (VelocidadEscala <= 0.02f)
        {
            Destroy();
            return;
        }

        MeshComp->SetWorldScale3D(FVector(VelocidadEscala));
    }
}

void ASubBloque::ActivarDesvanecimiento()
{
    bDestruirSubBloque = true;
    MeshComp->SetSimulatePhysics(false); // opcional: congelar mientras se reduce
}