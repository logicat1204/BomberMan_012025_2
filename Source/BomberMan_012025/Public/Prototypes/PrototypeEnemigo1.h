// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "PrototypeEnemigo1.generated.h"

UCLASS()
class BOMBERMAN_012025_API APrototypeEnemigo1 : public ACharacter
{
	GENERATED_BODY()

	USkeletalMeshComponent* MallaEnemigo;

	//Patrullar por un punto A y otro B

	UPROPERTY(EditAnywhere,Category="Patrullaje")
	FVector PuntoA;
	
	UPROPERTY(EditAnywhere,Category="Patrullaje")
	FVector PuntoB;

	UPROPERTY(EditAnywhere,Category="Movimiento")
	float VelocidadMovimiento=300.0f;

	//Detectar y perseguir jugador

	UPROPERTY(EditAnywhere,Category="Deteccion")
	USphereComponent* RangoVision;

	UPROPERTY()
	APawn* JugadorDetectado;

private:

	FVector DestinoActual;

public:
	// Sets default values for this character's properties
	APrototypeEnemigo1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnVerJugador(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnPerderJugador(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
