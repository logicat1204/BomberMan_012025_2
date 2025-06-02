// Fill out your copyright notice in the Description page of Project Settings.

#include "Patterns/Facade/GodModePowerUP.h"
#include "Kismet/GameplayStatics.h"
#include "Patterns/Facade/Facade_GodMode.h"
// Sets default values
AGodModePowerUP::AGodModePowerUP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaGodMode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaGodMode"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'"));
	if (MallaAsset.Succeeded())
	{
		MallaGodMode->SetStaticMesh(MallaAsset.Object);
	}
}

// Called when the game starts or when spawned
void AGodModePowerUP::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	
}

// Called every frame
void AGodModePowerUP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Dist_player = FVector::Dist(Player->GetActorLocation(), GetActorLocation());
	if (Dist_player < 150.0f) {
		execute_god_mode();
		this->Destroy();
	}
}

void AGodModePowerUP::execute_god_mode()
{
	GetWorld()->SpawnActor<AFacade_GodMode>(AFacade_GodMode::StaticClass(), GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
}

