// Fill out your copyright notice in the Description page of Project Settings.


#include "Prototypes/PrototypeEnemigo1.h"

// Sets default values
APrototypeEnemigo1::APrototypeEnemigo1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaEnemigo = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaEnemigo"));
	MallaEnemigo->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>AssetEnTerrestre(TEXT("/Script/Engine.SkeletalMesh'/Game/MonsterForSurvivalGame/Mesh/PBR/Beholder_SK.Beholder_SK'"));
	if (AssetEnTerrestre.Succeeded()) {
		MallaEnemigo->SetSkeletalMesh(AssetEnTerrestre.Object);
	}
}

// Called when the game starts or when spawned
void APrototypeEnemigo1::BeginPlay()
{
	Super::BeginPlay();
	
	DestinoActual = PuntoB;

	//Creacion de la esfera
	RangoVision = CreateDefaultSubobject<USphereComponent>(TEXT("RangoVision"));
	RangoVision->SetupAttachment(RootComponent);
	RangoVision->SetSphereRadius(400.0f);
	RangoVision->SetCollisionProfileName(TEXT("Trigger"));

	//Delegados para saber si algo entra o sale del radio de la esfera
	RangoVision->OnComponentBeginOverlap.AddDynamic(this, &APrototypeEnemigo1::OnVerJugador);
	RangoVision->OnComponentEndOverlap.AddDynamic(this, &APrototypeEnemigo1::OnPerderJugador);
}

// Called every frame
void APrototypeEnemigo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector posicion_actual = GetActorLocation();

	FVector Direccion = (DestinoActual - posicion_actual).GetSafeNormal();

	FVector nueva_posicion = posicion_actual + Direccion * VelocidadMovimiento * DeltaTime;

	SetActorLocation(nueva_posicion);

	float Distancia = FVector::Dist(posicion_actual, DestinoActual);
	if (Distancia < 100.0f) 
	{
		DestinoActual = (DestinoActual.Equals(PuntoA)) ? PuntoB : PuntoA;
	}

	//Logica para calcular posicon del jugador 

	FVector DestinoFinal;

	if (JugadorDetectado)
	{
		DestinoFinal = JugadorDetectado->GetActorLocation(); // Perseguir al jugador
	}
	else
	{
		DestinoFinal = DestinoActual; // Seguir patrullando
	}

	// Mover hacia destino final (igual que antes)
	Direccion = (DestinoFinal - GetActorLocation()).GetSafeNormal();
	AddMovementInput(Direccion, 1.0f);
}

// Called to bind functionality to input
void APrototypeEnemigo1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



//funciones detectar jugador
void APrototypeEnemigo1::OnVerJugador(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ¿Es el jugador?
	APawn* Jugador = Cast<APawn>(OtherActor);
	if (Jugador && Jugador != this) {
		JugadorDetectado = Jugador;
		UE_LOG(LogTemp, Warning, TEXT("¡Jugador detectado!"));
	}
}

void APrototypeEnemigo1::OnPerderJugador(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == JugadorDetectado) {
		JugadorDetectado = nullptr;
		UE_LOG(LogTemp, Warning, TEXT("Jugador perdido..."));
	}
}