// Fill out your copyright notice in the Description page of Project Settings.


#include "Prototypes/BlockWithDestruction/BloquePrototype.h"
#include "Prototypes/BlockWithDestruction/SubBloque.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
ABloquePrototype::ABloquePrototype()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    RootComponent = MeshComp;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube"));
    if (CubeMesh.Succeeded())
    {
        MeshComp->SetStaticMesh(CubeMesh.Object);
    }

    MeshComp->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void ABloquePrototype::BeginPlay()
{
	Super::BeginPlay();
    DestruirBloque();
    FTimerHandle TimerHandle_Desvanecer;
    GetWorldTimerManager().SetTimer(TimerHandle_Desvanecer, this, &ABloquePrototype::ActivarDesvanecimientoSubbloques, 4.0f, false);
}


void ABloquePrototype::DestruirBloque()
{
    FVector Origin = GetActorLocation();

    // Oculta el original
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);

    // Fragmenta en 8 cubos pequeños (2x2x2)
    for (int x = 0; x < 2; ++x)
    {
        for (int y = 0; y < 2; ++y)
        {
            for (int z = 0; z < 2; ++z)
            {
                FVector Offset(x * 30.f, y * 30.f, z * 30.f);
                FVector SpawnLocation = Origin + Offset;

                FActorSpawnParameters Params;
                Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

                ASubBloque* Fragmento = GetWorld()->SpawnActor<ASubBloque>(ASubBloque::StaticClass(), SpawnLocation, FRotator::ZeroRotator, Params);

                if (Fragmento)
                {
                    // Aplica impulso aleatorio para simular explosión
                    FVector Impulso = FVector(FMath::RandRange(-200, 2000), FMath::RandRange(-200, 2000), FMath::RandRange(500, 2000));
                    Fragmento->FindComponentByClass<UStaticMeshComponent>()->AddImpulse(Impulso);
                    SubBloquesGuardados.Add(Fragmento);
                }
            }
        }
    }

    // Destruye el actor original después de 1 segundo
   SetLifeSpan(5.0f);
}

void ABloquePrototype::ActivarDesvanecimientoSubbloques()
{
    for (ASubBloque* Fragmento : SubBloquesGuardados)
    {
        if (Fragmento)
        {
            Fragmento->ActivarDesvanecimiento();
        }
    }
}
