// Fill out your copyright notice in the Description page of Project Settings.



#include "Patterns/Prototype/EnemigoClonable.h"

// Sets default values
AEnemigoClonable::AEnemigoClonable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    EnemyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaEnemigo"));
    RootComponent = EnemyMesh;
    ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyAssetMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/MonsterForSurvivalGame/Mesh/Polyart/Cactus_SK.Cactus_SK'"));
    if (EnemyAssetMesh.Succeeded()) {
        EnemyMesh->SetSkeletalMesh(EnemyAssetMesh.Object);
    }

}

// Called when the game starts or when spawned
void AEnemigoClonable::BeginPlay()
{
	Super::BeginPlay();
    FTimerHandle TimerProto;
    GetWorldTimerManager().SetTimer(TimerProto, this, &AEnemigoClonable::ClonarActor, 5.f, false);
}

// Called every frame
void AEnemigoClonable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    ChangeSize(); // Llama a la función en cada frame
}

AActor* AEnemigoClonable::Clonar()
{
        FActorSpawnParameters SpawnParams;
        SpawnParams.Template = this; // Usa el actor actual como plantilla
        return GetWorld()->SpawnActor<AEnemigoClonable>(GetClass(), GetActorLocation(), GetActorRotation(), SpawnParams);

}

void AEnemigoClonable::ClonarActor()
{
    AActor* Clon = Clonar();
    Clon->SetActorLocation(GetActorLocation()+FVector(2000.0f,0.0f,0.0f));
}

void AEnemigoClonable::ChangeSize()
{
    {
        FVector NewScale = GetActorScale3D();

        // Si el actor está aumentando de tamaño
        if (bIsGrowing)
        {
            NewScale += FVector(ScaleSpeed * GetWorld()->GetDeltaSeconds()); // Incrementa la escala
            if (NewScale.X >= MaxScale)
            {
                bIsGrowing = false; // Cambia a modo de reducción
            }
        }
        else
        {
            NewScale -= FVector(ScaleSpeed * GetWorld()->GetDeltaSeconds()); // Reduce la escala
            if (NewScale.X <= MinScale)
            {
                bIsGrowing = true; // Cambia a modo de crecimiento
            }
        }

        SetActorScale3D(NewScale);

    }

}
