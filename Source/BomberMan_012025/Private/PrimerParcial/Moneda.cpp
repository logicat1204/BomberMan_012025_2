// Fill out your copyright notice in the Description page of Project Settings.

#include "PrimerParcial/Moneda.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMoneda::AMoneda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MallaMoneda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMoneda"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> AssetMoneda(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	if (AssetMoneda.Succeeded())
	{
		MallaMoneda->SetStaticMesh(AssetMoneda.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> M_Moneda(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (M_Moneda.Succeeded())
	{
		MallaMoneda->SetMaterial(0, M_Moneda.Object);
	}
	MallaMoneda->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	MallaMoneda->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.1f));
}

// Called when the game starts or when spawned
void AMoneda::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TH_rotar, this, &AMoneda::rotar, velocidadRotacion, true);
	GameModeActual = Cast<ABomberMan_012025GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AMoneda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMoneda::rotar()
{
	if (ciclo_completo == true)
	{
		int32 tp_espacio_en_blanco = GameModeActual->EspaciosEnBlanco.Num();
		int32 nueva_locacion = FMath::RandRange(0, tp_espacio_en_blanco-1);
		SetActorLocation(GameModeActual->EspaciosEnBlanco[nueva_locacion]);
		SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 200.0f));
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Blue, TEXT("Se ha completado un CICLO de la moneda, la moneda cambio de locacion."));
		ciclo_completo = false;
	}
	if (pos_rot==360)
	{ 

		SetActorRotation(FRotator(90.0f, 0.0f, 0.0f));
		if (sentido_rotacion == 1) 
		{
			sentido_rotacion = 2;
			cont_sub_ciclo++;
		}
		else if (sentido_rotacion == 2) 
		{
			sentido_rotacion = 1;
			cont_sub_ciclo++;
		}
		if (cont_sub_ciclo == ciclos*2)
		{
			ciclo_completo = true;
			cont_sub_ciclo = 0;
		}
		pos_rot = 0;
	}
	if (sentido_rotacion == 1)
	{
		SetActorRotation(GetActorRotation() + FRotator(0.0f, 0.0f, 30.0f));
		nueva_rot = GetActorRotation();
		pos_rot += 30;
	}
	if (sentido_rotacion == 2)
	{
		SetActorRotation(GetActorRotation() - FRotator(0.0f, 0.0f, 30.0f));
		nueva_rot = GetActorRotation();
		pos_rot += 30;
	}
}

