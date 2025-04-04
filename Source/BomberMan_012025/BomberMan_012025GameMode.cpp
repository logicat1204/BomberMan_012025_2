// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"


ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}

void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();
	GenerarNivel(FVector(620.0f, -2330.0f, 0.0f), NivelBomberman50x50);

	
}

void ABomberMan_012025GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomberMan_012025GameMode::GenerarNivel(FVector locacionGenerar, TArray<TArray<int32>> ArregloNivel)
{
	/*
	* Se implemento una logica para spawnear enemigos en las zonas que sean 0.
	* Se usan dos contadores, uno para saber un limite de en cuantos espacios pueden aparecer los enemigos
	* El otro para que dentro del case 0 se sepa en que posiciones estan los 0 y poder colocar el lugar que
	* se le haya asignado para aparecer a un enemigo.
	* */
	int32 limite_enemigos = 0;
	int32 posicion_spawn=0;
	for (int32 j = 0; j < ArregloNivel.Num(); j++) {
		for (int32 k = 0; k < ArregloNivel[j].Num(); k++) {
			if (ArregloNivel[j][k] == 0) limite_enemigos++;
		}
	}
	

	AEnemigo* EnemigoSpawneado = nullptr;

	int32 pos_en1 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en2 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en3 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en4 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en5 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en6 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en7 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en8 = FMath::RandRange(1, limite_enemigos);
	ABloque* BloqueGenerado = nullptr;
	bool setAleatorio = false;
	int32 limite_ale = FMath::RandRange(2, 6);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Numero de bloques aleatorios con comportamiento: %d"), limite_ale));
	LugarAparicion.SetLocation(locacionGenerar);
	for (int32 j = 0; j < ArregloNivel.Num(); j++)
	{
		for (int32 k = 0; k < ArregloNivel[j].Num(); k++)
		{
			//genera los 5 aleatoriosd de todo el nivel
			bAleatorio = FMath::RandBool();
			if (bAleatorio == true&&ArregloNivel[j][k]!=0){
				if (ArregloNivel[j][k] != 4) {
					setAleatorio = true;
					cont_b_ale++;
				}
			}
			switch (ArregloNivel[j][k])
			{
			case 0:
				posicion_spawn++;
				if (posicion_spawn == pos_en1) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAereo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo aereo Spawneado"));
				}
				if (posicion_spawn == pos_en2) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAereo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo aereo Spawneado"));
				}
				if (posicion_spawn == pos_en3) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoTerrestre::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo terrestre Spawneado"));
				}
				if (posicion_spawn == pos_en4) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoTerrestre::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo terrestre Spawneado"));
				}
				if (posicion_spawn == pos_en5) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoSubterraneo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo subterraneo Spawneado"));
				}
				if (posicion_spawn == pos_en6) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoSubterraneo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo subterraneo Spawneado"));
				}
				if (posicion_spawn == pos_en7) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAcuatico::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo acuatico Spawneado"));
				}
				if (posicion_spawn == pos_en8) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAcuatico::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo acuatico Spawneado"));
				}
				if (EnemigoSpawneado)
				{
					aEnemigos.Add(EnemigoSpawneado);
				}
				break;
			case 1:
				if (setAleatorio == true && cont_b_ale<=limite_ale)
				{
				LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
				BloqueGenerado=GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMaderaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{ 
				LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
				BloqueGenerado=GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), LugarAparicion);
				}
				break;
			case 2:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueLadrillo2>(AMyBloqueLadrillo2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueLadrillo2>(ABloqueLadrillo2::StaticClass(), LugarAparicion);
				}
				break;
			case 3:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueConcreto2>(AMyBloqueConcreto2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueConcreto2>(ABloqueConcreto2::StaticClass(), LugarAparicion);
				}
				break;
			case 4:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueAcero2>(AMyBloqueAcero2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueAcero2>(ABloqueAcero2::StaticClass(), LugarAparicion);
				}
				break;
			}
			// Agregar el bloque al TArray si fue generado
			if (BloqueGenerado)
			{
				aBloques.Add(BloqueGenerado);
			}
			setAleatorio = false;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Nivel generado"));
	cont_b_ale = 0;
}


