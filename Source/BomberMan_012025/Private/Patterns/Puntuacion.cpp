// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Puntuacion.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APuntuacion::APuntuacion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TArray<AActor*> Instancias;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuntuacion::StaticClass(), Instancias);
	if (Instancias.Num() >= 1)
	{
		Instancia = Cast<APuntuacion>(Instancias[0]);
		Destroy();
	}
}

// Called when the game starts or when spawned
void APuntuacion::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TH_show_puntuacion, this, &APuntuacion::show_puntuacion, 5.0f, true);
}

// Called every frame
void APuntuacion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuntuacion::show_puntuacion()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Puntuacion total: %d"),puntuacion_tot));
}

