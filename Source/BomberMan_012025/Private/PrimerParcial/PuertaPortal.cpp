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

	// Evento de colisión
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APuertaPortal::AlTocarJugador);
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


void APuertaPortal::AlTocarJugador(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Evitar teletransporte si no se puede
	if (!bPuedeTeletransportar) return;

	// Verificar que el actor que tocó la puerta es el jugador
	if (OtherActor && OtherActor->IsA<ACharacter>())
	{
		// Asegúrate de que sea el jugador. Si usas ACharacter como base para enemigos,
		// puedes agregar una verificación adicional para diferenciarlos (por ejemplo, comprobando
		// si el actor es de tipo jugador).
		ACharacter* Character = Cast<ACharacter>(OtherActor);
		if (Character && Character != nullptr && Character->IsPlayerControlled())
		{
			// Código para teletransportar al jugador
			ABomberMan_012025GameMode* GM = Cast<ABomberMan_012025GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
			if (GM && GM->PuertasPortal.Num() > 1)
			{
				AActor* nuevaPuerta = nullptr;

				// Elegir una puerta distinta a esta
				do {
					int32 indice = FMath::RandRange(0, GM->PuertasPortal.Num() - 1);
					nuevaPuerta = GM->PuertasPortal[indice];
				} while (nuevaPuerta == this);

				if (nuevaPuerta)
				{
					bPuedeTeletransportar = false; // evitar bucle
					Character->SetActorLocation(nuevaPuerta->GetActorLocation());

					// Muy importante: habilitar teletransporte después de un tiempo
					FTimerHandle TimerHandle;
					GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {
						bPuedeTeletransportar = true;
						}, 1.0f, false); // espera 1 segundo para habilitarlo otra vez
				}
			}
		}
	}
}