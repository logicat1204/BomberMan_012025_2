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

	TransportarJugadorAlPlayerStart(); //  Aquí se mueve el jugador para corregir el tp al asignar 
	//una nueva posicion al PlayerStart debido a que lo hice en la funcion GenerarNivel.

	lab_01_muro();
	lab_02_10bloques();

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
	BuscarPuertasPortal();

	GenerarParkour(FVector(850.0f, 2750.0f, 0.0f));
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


				if (posicion_spawn == pos_p1) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
				}
				if (posicion_spawn == pos_p2) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
				}
				if (posicion_spawn == pos_en3) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
				}
				if (posicion_spawn == pos_en4) {
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					GetWorld()->SpawnActor<APuertaPortal>(APuertaPortal::StaticClass(), LugarAparicion);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, TEXT("Puerta colocada"));
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
			case 5:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAguaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAgua::StaticClass(), LugarAparicion);
				}
				break;
			case 6:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueArena>(ABloqueArenaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueArena>(ABloqueArena::StaticClass(), LugarAparicion);
				}
				break;
			case 7:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueCesped>(ABloqueCespedFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueCesped>(ABloqueCesped::StaticClass(), LugarAparicion);
				}
				break;
			case 8:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOroFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), LugarAparicion);
				}
				break;
			case 9:
				if (setAleatorio == true && cont_b_ale <= limite_ale)
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
					BloqueGenerado = GetWorld()->SpawnActor<ABloqueRoca>(ABloqueRocaFuncional::StaticClass(), LugarAparicion);
				}
				else
				{
					LugarAparicion.SetLocation(FVector(locacionGenerar.X + (100.0f * j), locacionGenerar.Y + (100.0f * k), 0.0));
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



//Funcionar para corregir la posicion Inicial del jugador al cambiar de lugar el PlayerStart
void ABomberMan_012025GameMode::TransportarJugadorAlPlayerStart()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Buscar el primer PlayerStart (o puedes filtrar uno específico si quieres)
	APlayerStart* MiPlayerStart = nullptr;

	for (TActorIterator<APlayerStart> It(World); It; ++It)
	{
		MiPlayerStart = *It;
		break; // Solo usamos el primero que encontremos
	}

	if (!MiPlayerStart) return;

	// Obtener el PlayerController y su Pawn (el Character)
	APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
	if (PC && PC->GetPawn())
	{
		// Mover al Character a la ubicación del PlayerStart
		PC->GetPawn()->SetActorLocation(MiPlayerStart->GetActorLocation());
		PC->GetPawn()->SetActorRotation(MiPlayerStart->GetActorRotation());

		UE_LOG(LogTemp, Warning, TEXT("Jugador transportado al PlayerStart: %s"), *MiPlayerStart->GetActorLocation().ToString());
	}
}

void ABomberMan_012025GameMode::CambiarBloque()
{
	if (aBloquesCambiables.Num() == 0) return;

	int32 bloqueColocar = 0;
	int32 tamano_bloques_a_cambiar = aBloquesCambiables.Num();

	int32 bloqueCambio = FMath::RandRange(0, tamano_bloques_a_cambiar - 1);
	FVector posicion_colocar = aBloquesCambiables[bloqueCambio]->GetActorLocation();

	aBloquesCambiables[bloqueCambio]->Destroy();

	do {
		bloqueColocar = FMath::RandRange(1, 10);
	} while (bloqueColocar == 4); // puedes ajustar esta lógica si solo quieres tipo 4

	LugarAparicion.SetLocation(posicion_colocar);

	switch (bloqueColocar)
	{
	case 1: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), LugarAparicion); break;
	case 2: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueLadrillo2>(ABloqueLadrillo2::StaticClass(), LugarAparicion); break;
	case 3: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueConcreto2>(ABloqueConcreto2::StaticClass(), LugarAparicion); break;
	case 5: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAgua::StaticClass(), LugarAparicion); break;
	case 6: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), LugarAparicion); break;
	case 7: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueArena>(ABloqueArena::StaticClass(), LugarAparicion); break;
	case 8: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), LugarAparicion); break;
	case 9: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueRoca>(ABloqueRoca::StaticClass(), LugarAparicion); break;
	case 10: aBloquesCambiables[bloqueCambio] = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), LugarAparicion); break;
	default:	break;
				
	}

	GEngine->AddOnScreenDebugMessage(-1, 6.0f, FColor::Yellow, TEXT("Un bloque ha sido cambiado"));
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
		GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), bloque_parkour);
	}
}


FTransform muro_ubi;

void ABomberMan_012025GameMode::lab_01_muro() {
	for (int32 o = 0; o < 43; o++) {
		muro_ubi.SetLocation(FVector(3130.0f,2460.0f - (100.0f * o),0.0f));
		GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), muro_ubi);
	}
}

FTransform bloques10;
int32 contb=0;

void ABomberMan_012025GameMode::lab_02_10bloques() {
	FVector coordA = FVector(3030.0f,2450.0f,0.0f);
	for (int32 q = 0; q <= 23; q++) {
			contb++;
			int32 rangoX = FMath::RandRange(1, 23);
			int32 rangoY = FMath::RandRange(1, 20);
			switch (contb) {
			case 1:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), bloques10);
				break;
			case 2:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAgua::StaticClass(), bloques10);
				break;
			case 3:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueArena>(ABloqueArena::StaticClass(), bloques10);
				break;
			case 4:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueLadrillo2>(ABloqueLadrillo2::StaticClass(), bloques10);
				break;
			case 5:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), bloques10);
				break;
			case 6:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueCesped>(ABloqueCesped::StaticClass(), bloques10);
				break;
			case 7:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), bloques10);
				break;
			case 8:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueAcero2>(ABloqueAcero2::StaticClass(), bloques10);
				break;
			case 9:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueConcreto2>(ABloqueConcreto2::StaticClass(), bloques10);
				break;
			case 10:
				bloques10.SetLocation(FVector(coordA.X - (100.0f * rangoX), coordA.Y - (100.0f * rangoY), coordA.Z));
				GetWorld()->SpawnActor<ABloqueRoca>(ABloqueRoca::StaticClass(), bloques10);
				break;
			}

		}
	contb = 0;
	}



void ABomberMan_012025GameMode::Eliminar()
{
	int numeroEnemigos = aEnemigos.Num();
	
	if (aEnemigos.Num()>numeroEnemigos / 2) {

		EnemigoActual = aEnemigos[numeroEnemigos-1]; 
		if (EnemigoActual)
		{
			EnemigoActual->Destroy();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Un enemigo ha sido eliminado."));
		}
	}
}