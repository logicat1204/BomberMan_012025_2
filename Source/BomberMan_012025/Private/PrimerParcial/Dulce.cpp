// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimerParcial/Dulce.h"
#include "Kismet/GameplayStatics.h"
#include "Patterns/Inventory.h"
#include "Patterns/Puntuacion.h"

AInventory* inventario;
APuntuacion* puntuacion;
// Sets default values
ADulce::ADulce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaDulce = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDulce"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> AssetMallaDulce(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (AssetMallaDulce.Succeeded())
	{
		MallaDulce->SetStaticMesh(AssetMallaDulce.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> M_MallaDulce(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Walnut.M_Wood_Walnut'"));
	if (M_MallaDulce.Succeeded())
	{
		MallaDulce->SetMaterial(0, M_MallaDulce.Object);
	}
}

// Called when the game starts or when spawned
void ADulce::BeginPlay()
{
	Super::BeginPlay();
	posiciones_tp.SetNum(nro_max_pos);
	posiciones_tp[0] = GetActorLocation();
	for (int i = 1; i < posiciones_tp.Num(); i++)
	{
		float new_pos_x = FMath::RandRange(-3000.0f, 3000.0f);
		float new_pos_y = FMath::RandRange(-3000.0f, 3000.0f);
		FVector add_pos = FVector(new_pos_x,new_pos_y,300.0f);
		//INCORRECTO: AGREGA AL FINAL DEL VECTOR posiciones_tp.Add(add_pos);
		//CORRECTO: AGREGA AL VECTOR
		posiciones_tp[i] = GetActorLocation() + add_pos;
	}
	MiJugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	GetWorldTimerManager().SetTimer(TH_next, this, &ADulce::previous, tiempo_tp, true);

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInventory::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
	{
		inventario = Cast<AInventory>(FoundActors[0]);
	}

	TArray<AActor*> Puntuaciones;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuntuacion::StaticClass(), Puntuaciones);
	if (Puntuaciones.Num() > 0)
	{
		puntuacion = Cast<APuntuacion>(Puntuaciones[0]);
	}
}

// Called every frame
void ADulce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	comer_dulce();
}

void ADulce::next()
{
	if (nroDePosicion >= 0 && nroDePosicion<nro_max_pos)
	{
		SetActorLocation(posiciones_tp[nroDePosicion]);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, TEXT("El dulce ha cambiado de posicion."));
		nroDePosicion++;
	}
	if (nroDePosicion == 4)
	{
		nroDePosicion = 0;
	}
	asignar_puntuacion();
}

void ADulce::previous()
{
	if (nroDePosicion >= 0 && nroDePosicion < nro_max_pos)
	{
		SetActorLocation(posiciones_tp[nroDePosicion]);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, TEXT("El dulce ha cambiado de posicion."));
		nroDePosicion--;
	}
	if (nroDePosicion < 0)
	{
		nroDePosicion = 3;
	}
	asignar_puntuacion();
}

void ADulce::comer_dulce()
{
	float dist_dulce_jugador = FVector::Dist(GetActorLocation(), MiJugador->GetActorLocation());
	if (dist_dulce_jugador <= 200.0f)
	{
		if (inventario)
		{
			inventario->cant_dulces++;
			Destroy();
			GEngine->AddOnScreenDebugMessage(-1, 6.0f, FColor::Red, TEXT("EL JUGADOR HA COMIDO UN DULCE."));
			GEngine->AddOnScreenDebugMessage(-1, 6.0f, FColor::Yellow, FString::Printf(TEXT("Ha puntuado: %d"), puntuacion->puntuacion_tot));
		}
		if (puntuacion)
		{
			puntuacion->puntuacion_tot += asig_pt;
		}
	}
}


void ADulce::asignar_puntuacion()
{
	float dist_dulce_jugador = FVector::Dist(GetActorLocation(), MiJugador->GetActorLocation());
	if (dist_dulce_jugador >= 0.0f && dist_dulce_jugador <= 500.0f)
	{
		asig_pt = 100;
	}
	if (dist_dulce_jugador > 500.0f && dist_dulce_jugador <= 1000.0f)
	{
		asig_pt = 200;
	}
	if (dist_dulce_jugador > 1000.0f && dist_dulce_jugador <= 2000.0f)
	{
		asig_pt = 400;
	}
}

