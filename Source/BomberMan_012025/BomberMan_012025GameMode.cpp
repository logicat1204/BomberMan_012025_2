// Copyright Epic Games, Inc. All Rights Reserved.
#include "BomberMan_012025GameMode.h"
#include "Patterns/AbstractFactory/FabricaBloquesMagicos.h"
#include "Patterns/AbstractFactory/FabricaBloquesNormales.h"

#include "Patterns/BuilderNuevo/DirectorNiveles.h"
#include "Patterns/BuilderNuevo/NivelBomberman.h"
#include "SegundoParcial/EnemigoNormal.h"
#include "SegundoParcial/Comandante.h"
#include "SegundoParcial/DirectorEjercitos.h"
#include "SegundoParcial/BuilderEjercito.h"

#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Patterns/FactoryMethod/FabricaDeBloques.h"



ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	//Primer Parcial
	//activar el tick del GameMode
	PrimaryActorTick.bCanEverTick = true;
}
AFabricaDeBloques* Fabr;
void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();
	//SEGUNDO PARCIAL
	ADirectorNiveles* DirectorNivel = GetWorld()->SpawnActor<ADirectorNiveles>(ADirectorNiveles::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
	ANivelBomberman* Nivel = DirectorNivel->Builder->ObtenerNivel();
	ADirectorEjercitos* DirectorEjercitos = GetWorld()->SpawnActor<ADirectorEjercitos>(ADirectorEjercitos::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
	ABuilderEjercito* BuilderEjercito = GetWorld()->SpawnActor<ABuilderEjercito>(ABuilderEjercito::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
	DirectorEjercitos->SetBuilder(BuilderEjercito);
	DirectorEjercitos->SetEspaciosColocarEnemigos(Nivel->EspaciosEnBlanco);
	DirectorEjercitos->CrearEjercito();
	/*
	//Instanciar fabrica de bloques FACTORY METHOD y tambien spawnear bloques.
	Fabr = GetWorld()->SpawnActor<AFabricaDeBloques>(AFabricaDeBloques::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
	Fabr->CrearBloque(AFabricaDeBloques::Acero, FVector(850.0f, 2750.0f, 0.0f));
	Fabr->CrearBloque(AFabricaDeBloques::Madera, FVector(850.0f+100.0f, 2750.0f, 0.0f));
	Fabr->CrearBloque(AFabricaDeBloques::Agua, FVector(850.0f+200.0f, 2750.0f, 0.0f));
	Fabr->CrearBloque(AFabricaDeBloques::Ladrillo, FVector(850.0f+300.0f, 2750.0f, 0.0f));
	Fabr->CrearBloque(AFabricaDeBloques::Roca, FVector(850.0f+400.0f, 2750.0f, 0.0f));
	Fabr->CrearBloque(AFabricaDeBloques::Concreto, FVector(850.0f+500.0f, 2750.0f, 0.0f));
	Fabr->CrearBloque(AFabricaDeBloques::Arena, FVector(850.0f+600.0f, 2750.0f, 0.0f));
	*/
	/*
	ABuilderNivelGrande* Builder1;
	ABuilderNivelPequeno* Builder2;
	ABuilderNivelMediano* Builder3;
	Builder3 = GetWorld()->SpawnActor<ABuilderNivelMediano>(ABuilderNivelMediano::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Builder2 = GetWorld()->SpawnActor<ABuilderNivelPequeno>(ABuilderNivelPequeno::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Builder1 = GetWorld()->SpawnActor<ABuilderNivelGrande>(ABuilderNivelGrande::StaticClass(), FVector(0.0f,0.0f,0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass(), FVector(0.0f,0.0f,0.0f), FRotator(0.0f,0.0f,0.0f));
	if (Director) {
		Director->AsignarBuilder(Builder1);
		Director->CrearNivel(FVector(140.0f, 3350.0f, 0.0f));
		Director->AsignarBuilder(Builder2);
		Director->CrearNivel(FVector(5810.0f, 1650.0f, 0.0f));
		Director->AsignarBuilder(Builder3);
		Director->CrearNivel(FVector(5810.0f, -3660.0, 0.0f));
	}
	*/
	//Antiguo Sistema de generacion, sin creador de niveles:
	//GenerarNivel(FVector(620.0f, -2330.0f, 0.0f), NivelInferior);
	//Nuevo sistema de generacion:
	//CrearNivel(20.0f, 20.0f, 50.0f,aNivelCreado);
	//GenerarNivel(FVector(620.0f, -2330.0f, 0.0f), aNivelCreado);
	//CambiarBloque();
	//TransportarJugadorAlPlayerStart(); //  Aquí se mueve el jugador para corregir el tp al asignar 
	//una nueva posicion al PlayerStart debido a que lo hice en la funcion GenerarNivel.

	//GetWorldTimerManager().SetTimer(TemporizadorCambioBloque, this, &ABomberMan_012025GameMode::CambiarBloque, 15.0f, true);
	/*
	GetWorldTimerManager().SetTimer(
		EliminarEnemigo,
		this,
		&ABomberMan_012025GameMode::Eliminar,
		3.0f,
		true
	);
	*/
	//BuscarPuertasPortal();

	//GenerarParkour(FVector(850.0f, 2750.0f, 0.0f));

	//PrimerParcial
	//Guardo al jugador como una variable de tipo pawn
	MiJugador = UGameplayStatics::GetPlayerPawn(this, 0);
	
	//Primer Parcial - 2
	//TPEspacioEnBlanco();
	//p1_posicionar();
	APlayerController* Controlador = GetWorld()->GetFirstPlayerController();
	if (Controlador)
	{
		Controlador->InputComponent->BindAction("SpawnBomba", IE_Pressed, this, &ABomberMan_012025GameMode::SpawnBomba);
	}

	//P2
	//GetWorldTimerManager().SetTimer(TemporizadorCambioBloque, this, &ABomberMan_012025GameMode::CambiarBloque, 5.0f, true);
	// 
	AFabricaBloquesNormales* FabricaBloques = GetWorld()->SpawnActor<AFabricaBloquesNormales>(AFabricaBloquesNormales::StaticClass());
	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aNivelCreado.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aNivelCreado[fila].Num(); ++columna)
		{
			int32 valor = aNivelCreado[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(XInicial + columna * AnchoBloque,YInicial + fila * LargoBloque,20.0f); 
				// Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				//SpawnBloque(posicionBloque, valor);
				switch (valor)
				{
				case 1: // Madera
					FabricaBloques->ColocarBloque("Madera", posicionBloque);
					//SpawnBloque(posicionBloque, 1);
					break;
				case 2: // Ladrillo
					FabricaBloques->ColocarBloque("Acero", posicionBloque);
				default:
					break;
				}
			}
		}
	}
	float XInicial2 = 3000.00f;
	float YInicial2 = 2500.00f;
	//fabrica bloques magicos
	AFabricaBloquesMagicos* FabricaBloques2 = GetWorld()->SpawnActor<AFabricaBloquesMagicos>(AFabricaBloquesMagicos::StaticClass());
	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aNivelCreado.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aNivelCreado[fila].Num(); ++columna)
		{
			int32 valor = aNivelCreado[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque2 = FVector(XInicial2 + columna * AnchoBloque, YInicial2 + fila * LargoBloque, 20.0f);
				// Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				//SpawnBloque(posicionBloque, valor);
				switch (valor)
				{
				case 1: // Madera
					FabricaBloques2->ColocarBloque("Madera", posicionBloque2);
					//SpawnBloque(posicionBloque, 1);
					break;
				case 2: // Ladrillo
					FabricaBloques2->ColocarBloque("Acero", posicionBloque2);
					break;
				default:
					break;
				}
			}
		}
	}
}


void ABomberMan_012025GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DetectarUsoPortal();
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
			if (ArregloNivel[j][k] == 0) {
				limite_enemigos++;
			}
		}
	}
	

	AEnemigo* EnemigoSpawneado = nullptr;
	//Asignar una posicion de Spawn aleatoria a los enemigos, las puertas y la posicion inicial del Jugador tambien.
	int32 pos_p1 = FMath::RandRange(1, limite_enemigos);
	int32 pos_p2 = FMath::RandRange(1, limite_enemigos);
	int32 pos_p3 = FMath::RandRange(1, limite_enemigos);
	int32 pos_p4 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en1 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en2 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en3 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en4 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en5 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en6 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en7 = FMath::RandRange(1, limite_enemigos);
	int32 pos_en8 = FMath::RandRange(1, limite_enemigos);
	int32 pos_startjugador = FMath::RandRange(1, limite_enemigos);

	ABloque* BloqueGenerado = nullptr;
	ABloque* BloqueCambiable = nullptr;

	bool setAleatorio = false;
	int32 limite_ale = FMath::RandRange(2, 6);//AQUI DEFINIMOS CUANTOS BLOQUES QUE TENGAN SU FUNCION SPAWNEARAN ALEATORIAMENTE EN UN RANGO DE 2 A 6 COMO PIDIO EN EL ECAMPUS
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
				//Guardamos las posiciones en blanco para poder invocar ahi a nuestro Bomberman
				EspaciosEnBlanco.Add(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
				posicion_spawn++;
				if (posicion_spawn == pos_startjugador)
				{
					//Buscar APlayerStart
					for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
					{
						APlayerStart* PlayerStart = *It;

						if (PlayerStart)
						{
							// Obtener componente raíz
							USceneComponent* Root = PlayerStart->GetRootComponent();
							if (Root)
							{
								// Cambiar movilidad a Movable
								Root->SetMobility(EComponentMobility::Movable);

								// Luego se puede mover sin errores
								FRotator NuevaRot(0.f, 90.f, 0.f);
								PlayerStart->SetActorLocationAndRotation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0), NuevaRot);
								GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Emerald, TEXT("Posicion inicial cambiada."));
							}
						}
					}
				}

				if (posicion_spawn == pos_en1) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAereo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo aereo Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en2) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAereo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo aereo Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en3) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoTerrestre::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo terrestre Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en4) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoTerrestre::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo terrestre Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en5) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoSubterraneo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo subterraneo Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en6) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoSubterraneo::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo subterraneo Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en7) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAcuatico::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo acuatico Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}
				}
				if (posicion_spawn == pos_en8) {
					SpawnEnemigo.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					EnemigoSpawneado = GetWorld()->SpawnActor<AEnemigo>(AEnemigoAcuatico::StaticClass(), SpawnEnemigo);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemigo acuatico Spawneado"));
					if (EnemigoSpawneado)
					{
						aEnemigos.Add(EnemigoSpawneado);
					}

				}

				//Colocar puertas
				if (posicion_spawn == pos_p1) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					PuertaActual=GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
					if (PuertaActual) {
						PuertasGuardadas.Add(PuertaActual);
					}
				}
				if (posicion_spawn == pos_p2) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					PuertaActual = GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
					if (PuertaActual) {
						PuertasGuardadas.Add(PuertaActual);
					}
				}
				if (posicion_spawn == pos_p3) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					PuertaActual = GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
					if (PuertaActual) {
						PuertasGuardadas.Add(PuertaActual);
					}
				}
				if (posicion_spawn == pos_p4) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					PuertaActual = GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
					if (PuertaActual) {
						PuertasGuardadas.Add(PuertaActual);
					}
				}


				break;
			case 1:
				if (setAleatorio == true && cont_b_ale<=limite_ale)
				{
				LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
				BloqueGenerado=GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMaderaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{ 
				LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
				BloqueGenerado=GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), LugarAparicion);
				}
				aBloquesMadera.Add(BloqueGenerado);
				break;
			case 2:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueLadrillo2>(AMyBloqueLadrillo2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueLadrillo2>(ABloqueLadrillo2::StaticClass(), LugarAparicion);
				}
				break;
			case 3:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueConcreto2>(AMyBloqueConcreto2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueConcreto2>(ABloqueConcreto2::StaticClass(), LugarAparicion);
				}
				break;
			case 4:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueAcero2>(AMyBloqueAcero2Funcional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado=GetWorld()->SpawnActor<ABloqueAcero2>(ABloqueAcero2::StaticClass(), LugarAparicion);
				}
				aBordes.Add(BloqueGenerado);
				break;
			case 5:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAguaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAgua::StaticClass(), LugarAparicion);
				}
				break;
			case 6:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueArena>(ABloqueArenaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueArena>(ABloqueArena::StaticClass(), LugarAparicion);
				}
				break;
			case 7:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueCesped>(ABloqueCespedFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueCesped>(ABloqueCesped::StaticClass(), LugarAparicion);
				}
				break;
			case 8:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOroFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), LugarAparicion);
				}
				break;
			case 9:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueRoca>(ABloqueRocaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (200.0f * j), locacionGenerar.Y + (200.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueRoca>(ABloqueRoca::StaticClass(), LugarAparicion);
				}
				break;
			case 10:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrioFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), LugarAparicion);
				}
				break;
			}
			// Agregar el bloque al TArray si fue generado
			if (BloqueGenerado)
			{
				aBloques.Add(BloqueGenerado);
			}
			// Agregar los bloques que sean diferentes de un bloque de borde disenado (4).
			int32 Valor = ArregloNivel[j][k];
			if (BloqueGenerado && Valor != 4)
			{
				aBloquesCambiables.Add(BloqueGenerado);	
			}
			setAleatorio = false;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Nivel generado"));
	cont_b_ale = 0;
}

void ABomberMan_012025GameMode::SpawnBloque(FVector posicionBloque, int32 tipoBloque)
{
	//ABloque* BloqueGenerado = nullptr;

	ABloque* BloqueGenerado = nullptr;
	// Elegir tipo de bloque basado en el valor
	if (tipoBloque == 5)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueBurbuja>(ABloqueBurbuja::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = Fabr->CrearBloque(AFabricaDeBloques::Arena, posicionBloque);
	}
	else if (tipoBloque == 4)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = Fabr->CrearBloque(AFabricaDeBloques::Acero, posicionBloque);
	}
	else if (tipoBloque == 3)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = Fabr->CrearBloque(AFabricaDeBloques::Roca, posicionBloque);
	}
	else if (tipoBloque == 2)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = Fabr->CrearBloque(AFabricaDeBloques::Madera, posicionBloque);
	}
	else if (tipoBloque == 1)
	{
		//BloqueGenerado = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		BloqueGenerado = Fabr->CrearBloque(AFabricaDeBloques::Ladrillo, posicionBloque);
	}
	else {
		return;
	}
	// Agregar el bloque al TArray si fue generado
	if (BloqueGenerado)
	{
		aBloques.Add(BloqueGenerado);
	}

}




void ABomberMan_012025GameMode::BuscarPuertasPortal()
{
	PuertasPortal.Empty(); // Limpia por si ya se llamó antes

	TArray<AActor*> puertasEncontradas;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuertaPortal::StaticClass(), puertasEncontradas);

	for (AActor* actor : puertasEncontradas)
	{
		APuertaPortal* puerta = Cast<APuertaPortal>(actor);
		if (puerta)
		{
			PuertasPortal.Add(puerta); // 
			tot_puertas++;
			FString mensaje = FString::Printf(TEXT("Puerta #%d encontrada"), tot_puertas);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, mensaje);
		}
	}
}

void ABomberMan_012025GameMode::GenerarParkour(FVector ubi_gen)
{
	FTransform bloque_parkour;
	//altura maxima que se podra generar el parkour ademas delimita cuantos bloques se iran colocando hacia eje Z+
	int32 altura_parkour = FMath::RandRange(15, 50);
	for (int i = 0; i < altura_parkour; i++) 
	{
		int32 rangoX = FMath::RandRange(1, 7);
		int32 rangoY = FMath::RandRange(1, 6);
		bloque_parkour.SetLocation(FVector(ubi_gen.X+(rangoX*100.0f), ubi_gen.Y+(rangoY*100.0f), ubi_gen.Z + (i * 50.0f)));
		ABloque* BloqueParkour=GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), bloque_parkour);
		BloqueParkour->SetActorScale3D(FVector(1.0f, 1.0f, 0.5f));
	}
}

void ABomberMan_012025GameMode::TiempoTP() 
{
	if(bPuertaTransporta==false){
	GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Black, TEXT("SE HA REACTIVADO EL TP"));
	bPuertaTransporta = true;
	}
	cooldown_puerta = FMath::RandRange(1, 10);
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Emerald, FString::Printf(TEXT("El nuevo cooldown de la puerta es : %f"), cooldown_puerta));
}

void ABomberMan_012025GameMode::TPEspacioEnBlanco()
{
	int32 pos_tp_inicio = FMath::RandRange(1, EspaciosEnBlanco.Num() - 1);
	FVector TPInicio=EspaciosEnBlanco[pos_tp_inicio];
	MiJugador->SetActorLocation(TPInicio);
	GEngine->AddOnScreenDebugMessage(1,12.0f,FColor::Green,TEXT("Se ha transportado al jugador a un espaio aleatorio."));
}

void ABomberMan_012025GameMode::SpawnBomba()
{
	if (GetWorld())
	{
		// Obtener el personaje controlado
		ABomberMan_012025Character* Personaje = Cast<ABomberMan_012025Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (Personaje)
		{
			// Obtener la posición y la orientación del personaje
			FVector PosicionPersonaje = Personaje->GetActorLocation();
			FRotator RotacionPersonaje = Personaje->GetActorRotation();

			// Calcular la ubicación delante del personaje
			FVector DireccionFrente = RotacionPersonaje.Vector(); // Vector hacia adelante
			FVector UbicacionSpawn = PosicionPersonaje + (DireccionFrente * 1.0f); // Ajusta la distancia (200.0f en este caso)
			UbicacionSpawn.Z -= 90.0f;
			// Rotación para la bomba (opcional, puede ser igual a la del personaje)
			FRotator RotacionSpawn = RotacionPersonaje;

			// Spawnear la bomba
			AActor* BombaSpawneada = GetWorld()->SpawnActor<ABomba>(ABomba::StaticClass(), UbicacionSpawn, RotacionSpawn);
			if (BombaSpawneada)
			{
				UE_LOG(LogTemp, Warning, TEXT("¡Bomba spawneada frente al personaje en %s!"), *UbicacionSpawn.ToString());
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ClaseBomba no está configurada."));
	}
}

//Primer Parcial
//P1
void ABomberMan_012025GameMode::p1_posicionar()
{
	//Ahora buscaremos el bloque de madera mas cercano a los bordes.
	for (int v = 0; v < aBordes.Num(); v++) 
	{
		for (int b = 0; b < aBloquesMadera.Num(); b++) 
		{
			FVector ubi1 = aBordes[v]->GetActorLocation();
			FVector ubi2 = aBloquesMadera[b]->GetActorLocation();
			dist_madera_borde = FVector::Dist(ubi1, ubi2);
			if (dist_madera_borde < dist_borde)
			{
				dist_borde = dist_madera_borde;
				TPBordeCercanoAMadera = ubi2;
			}
		}
	}
	MiJugador->SetActorLocation(TPBordeCercanoAMadera+FVector(0.0f,0.0f,300.0f));
	GEngine->AddOnScreenDebugMessage(-1, 11.0f, FColor::Yellow, TEXT("P1 : Se ha transportado al jugador a un bloque de madera cercano al borde."));
}

void ABomberMan_012025GameMode::DetectarUsoPortal()
{
	//Primer Parcial
//Logica para detectar si el jugador esta en alguna de las puertas: Estoy guardando la distancia entre dos actores y las comparo
//Con cada puerta que esta guardada en el TArray
	for (int i = 0; i < PuertasGuardadas.Num(); i++) {
		PuertaActual = PuertasGuardadas[i];
		if (PuertaActual && MiJugador)
		{
			FVector PosJugador = MiJugador->GetActorLocation();
			FVector PosPuerta = PuertaActual->GetActorLocation();

			float Distancia = FVector::Dist(PosJugador, PosPuerta);
			if (Distancia < 100.0f && bPuertaTransporta == true)
			{
				do {
					var_rand_puerta = FMath::RandRange(0, PuertasGuardadas.Num() - 1);
					PuertaNueva = PuertasGuardadas[var_rand_puerta];
				} while (PuertaNueva == PuertaActual); // ¡buscamos una puerta diferente!
				PuertaNueva = PuertasGuardadas[var_rand_puerta];
				FVector TpPuerta = PuertaNueva->GetActorLocation();
				if (PuertaNueva) {
					MiJugador->SetActorLocation(TpPuerta);
					GEngine->AddOnScreenDebugMessage(-1, 0.10f, FColor::Green, TEXT("El jugador ha usado un portal puerta."));
					bPuertaTransporta = false;
					//Crear un cooldown con un timer para el TP de las puertas
					GetWorldTimerManager().SetTimer(PuertaTransporta, this, &ABomberMan_012025GameMode::TiempoTP, cooldown_puerta, false);
				}
			}
		}
	}
}

//P2
void ABomberMan_012025GameMode::CambiarBloque()
{
	if (aBloquesCambiables.Num() == 0) return;

	int32 selec_aleatoria = FMath::RandRange(0, aBloquesCambiables.Num() - 1);
	ABloque* bloqueSeleccionado = aBloquesCambiables[selec_aleatoria];

	if (bloqueSeleccionado->IsA(ABloqueMadera::StaticClass()))
	{
		FVector loc = bloqueSeleccionado->GetActorLocation();
		FTransform transform;
		transform.SetLocation(loc);
		bloqueSeleccionado->Destroy();
		aBloquesCambiables.RemoveAt(selec_aleatoria);

		for (int i = 0; i < 2; i++)
		{
			ABloque* nuevo = GetWorld()->SpawnActor<ABloqueConcreto2>(ABloqueConcreto2::StaticClass(), transform);
			aBloquesCambiables.Add(nuevo);
			transform.AddToTranslation(FVector(100, 0, 0));
		}
	}
	else if (bloqueSeleccionado->IsA(ABloqueConcreto2::StaticClass()))
	{
		FVector loc = bloqueSeleccionado->GetActorLocation();
		FTransform transform;
		transform.SetLocation(loc);
		bloqueSeleccionado->Destroy();
		aBloquesCambiables.RemoveAt(selec_aleatoria);

		for (int i = 0; i < 2; i++)
		{
			ABloque* nuevo = GetWorld()->SpawnActor<ABloqueLadrillo2>(ABloqueLadrillo2::StaticClass(), transform);
			aBloquesCambiables.Add(nuevo);
			transform.AddToTranslation(FVector(100, 0, 0));
		}
	}
	else
	{
		// Ver si hay al menos 2 bloques de concreto
		TArray<ABloqueConcreto2*> bloquesConcreto;
		for (ABloque* bloque : aBloquesCambiables)
		{
			if (ABloqueConcreto2* b = Cast<ABloqueConcreto2>(bloque))
			{
				bloquesConcreto.Add(b);
			}
		}

		if (bloquesConcreto.Num() >= 2)
		{
			ABloqueConcreto2* bc1 = bloquesConcreto[0];
			ABloqueConcreto2* bc2 = bloquesConcreto[1];
			FVector loc = bc1->GetActorLocation();

			bc1->Destroy();
			bc2->Destroy();
			aBloquesCambiables.Remove(bc1);
			aBloquesCambiables.Remove(bc2);

			FTransform transform;
			transform.SetLocation(loc);
			ABloque* nuevo = GetWorld()->SpawnActor<ABloqueAcero2>(ABloqueAcero2::StaticClass(), transform);
			aBloquesCambiables.Add(nuevo);
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 6.0f, FColor::Yellow, TEXT("Se han cambiado los bloques en 5 seg."));
}

//P5
void ABomberMan_012025GameMode::CrearNivel(int32 ej_x, int32 ej_y, int32 cantidadBloques, TArray<TArray<int32>>& aNivel)
{
	int32 tam_nivel = ej_x * ej_y;
	int32 llenar = 0;

	// Inicializar la matriz
	aNivel.SetNum(ej_x);
	for (int i = 0; i < ej_x; i++)
	{
		aNivel[i].SetNum(ej_y);
	}

	// Colocar los bloques según la cantidad especificada
	while (llenar < cantidadBloques)
	{
		int32 i = FMath::RandRange(0, ej_x - 1);
		int32 j = FMath::RandRange(0, ej_y - 1);

		// Verificar que el espacio aún no tenga un bloque antes de asignarlo
		if (aNivel[i][j] == 0)
		{
			int32 tipoBloque = FMath::RandRange(1, 2); // Tipo de bloque aleatorio
			aNivel[i][j] = tipoBloque;
			llenar++;
		}
	}
}