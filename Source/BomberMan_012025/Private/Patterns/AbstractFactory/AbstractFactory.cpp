// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/AbstractFactory/AbstractFactory.h"

// Sets default values
AAbstractFactory::AAbstractFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbstractFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbstractFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

