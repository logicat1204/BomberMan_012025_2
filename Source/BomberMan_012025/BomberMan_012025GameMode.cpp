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
	GenerarNivel(FVector(450.0f, 340.0f, 0.0f), Nivel1);
	GenerarNivel(FVector(620.0f, -2330.0f, 0.0f), Nivel3);
}

void ABomberMan_012025GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomberMan_012025GameMode::GenerarNivel(FVector locacionGenerar, TArray<TArray<int32>> ArregloNivel)
{

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
				break;
			case 1:
				if (setAleatorio == true && cont_b_ale<=5)
				{
				LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
				GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMaderaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{ 
				LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
				GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), LugarAparicion);
				}
				break;
			case 2:
				if (setAleatorio == true && cont_b_ale <= 5)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<ABloqueLadrillo2>(AMyBloqueLadrillo2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<ABloqueLadrillo2>(ABloqueLadrillo2::StaticClass(), LugarAparicion);
				}
				break;
			case 3:
				if (setAleatorio == true && cont_b_ale <= 5)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<ABloqueConcreto2>(AMyBloqueConcreto2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<ABloqueConcreto2>(ABloqueConcreto2::StaticClass(), LugarAparicion);
				}
				break;
			case 4:
				if (setAleatorio == true && cont_b_ale <= 5)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<ABloqueAcero2>(AMyBloqueAcero2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<ABloqueAcero2>(ABloqueAcero2::StaticClass(), LugarAparicion);
				}
				break;
			}
			setAleatorio = false;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Nivel generado"));
	cont_b_ale = 0;
}


