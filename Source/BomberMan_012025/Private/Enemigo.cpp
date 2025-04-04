// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MallaEnemigo = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaEnemigo"));
	MallaAltEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaAlternativaEnemigo"));
	MallaEnemigo->SetupAttachment(RootComponent);

	/* AGREGAR ESQUELETO
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>AssetMallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	if (AssetMallaEnemigo.Succeeded()) {
		MallaEnemigo->SetSkeletalMesh(AssetMallaEnemigo.Object);
	}
	*/

}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	int32 mov_aleatorio = FMath::RandRange(1, 4);
	switch (mov_aleatorio) {
	case 1:
		MoverAdelante(1.0f);
	case 2:
		MoverDetras(1.0f);
	case 3:
		MoverDerecha(1.0f);
	case 4:
		MoverIzquierda(1.0f);
	}

}

// Called to bind functionality to input
void AEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/*
FUNCIONES PARA MOVER AL CARACTER EN UN CICLO TICK
*/
void AEnemigo::MoverAdelante(float value)
{
	FVector Ubi=GetActorLocation();
	SetActorLocation(FVector(Ubi.X,Ubi.Y+value,Ubi.Z));
}

void AEnemigo::MoverDetras(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X, Ubi.Y - value, Ubi.Z));
}

void AEnemigo::MoverDerecha(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X+value, Ubi.Y, Ubi.Z));
}

void AEnemigo::MoverIzquierda(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X-value, Ubi.Y, Ubi.Z));
}

void AEnemigo::Volar()
{
	if (vuelo < 350) 
	{
		FVector Ubi = GetActorLocation();
		SetActorLocation(FVector(Ubi.X, Ubi.Y, Ubi.Z+1.0f));
		vuelo++;
	}
}

