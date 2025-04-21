// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimerParcial/PuertaPortal.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BomberMan_012025/BomberMan_012025GameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APuertaPortal::APuertaPortal()
{
	PrimaryActorTick.bCanEverTick = true;

	bPuedeTeletransportar = true;
	//NO SE ESTA USANDO, ERA DE UN EXPERIMENTO ANTERIOR
	// Primero creamos el componente raíz
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	BoxCollision->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxCollision;

	// Crear el mesh visual (Mesh principal visible)
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	// Asignar mesh visual desde contenido
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaPuerta(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_DoorFrame.SM_DoorFrame'"));
	if (ObjetoMallaPuerta.Succeeded())
	{
		Mesh->SetStaticMesh(ObjetoMallaPuerta.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void APuertaPortal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuertaPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



bool APuertaPortal::CanBeBaseForCharacter(APawn* APawn) const
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, TEXT("Ey jugador! Me estas pisando!!!!"));
	return true;
}
