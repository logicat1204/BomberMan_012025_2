// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueRocaFuncional.h"

void ABloqueRocaFuncional::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MovimientoTimer, this, &ABloqueRocaFuncional::movimiento_aleatorio, 0.5f, true);
}
/*
	posicion_anterior = GetActorLocation();
	GetWorldTimerManager().SetTimer(
		ControladorTiempo,
		this,
		&ABloqueRocaFuncional::mover_bloque,
		0.5f,
		true);
}

void ABloqueRocaFuncional::mover_bloque()
{
	contadorTicks++;
	FVector posicion_actual = GetActorLocation();
	posicion_actual.X += mov_adelante;
	FVector posicion_nueva = posicion_actual;
	SetActorLocation(posicion_nueva);
	if (contadorTicks == 3) {
		SetActorLocation(posicion_anterior);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Regresa a su posicion"));
		contadorTicks = 0;
	}
}
*/

/*
FUNCIONES PARA MOVER AL CARACTER EN UN CICLO TICK
*/
void ABloqueRocaFuncional::MoverAdelante(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X, Ubi.Y + value, Ubi.Z));
}

void ABloqueRocaFuncional::MoverDetras(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X, Ubi.Y - value, Ubi.Z));
}


void ABloqueRocaFuncional::MoverDerecha(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X + value, Ubi.Y, Ubi.Z));
}

void ABloqueRocaFuncional::MoverIzquierda(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X - value, Ubi.Y, Ubi.Z));
}

void ABloqueRocaFuncional::MoverArriba(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X, Ubi.Y, Ubi.Z+value));
}

void ABloqueRocaFuncional::MoverAbajo(float value)
{
	FVector Ubi = GetActorLocation();
	SetActorLocation(FVector(Ubi.X, Ubi.Y, Ubi.Z - value));
}

void ABloqueRocaFuncional::movimiento_aleatorio()
{
	int32 elegir = FMath::RandRange(1, 6);
	switch (elegir)
	{
	case 1:
		MoverAdelante(100.0f);
		break;
	case 2:
		MoverDetras(100.0f);
		break;
	case 3:
		MoverDerecha(100.0f);
		break;
	case 4:
		MoverIzquierda(100.0f);
		break;
	case 5:
		MoverArriba(100.0f);
		break;
	case 6:
		MoverAbajo(100.0f);
		break;
	}
}
