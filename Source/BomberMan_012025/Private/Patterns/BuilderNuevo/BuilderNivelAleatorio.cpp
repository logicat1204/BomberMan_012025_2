// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/BuilderNuevo/BuilderNivelAleatorio.h"
#include "Patterns/FactoryMethod\FabricaDeBloques.h"
// Sets default values
ABuilderNivelAleatorio::ABuilderNivelAleatorio()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderNivelAleatorio::BeginPlay()
{
	Super::BeginPlay();
    ANivelBomb = GetWorld()->SpawnActor<ANivelBomberman>(ANivelBomberman::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
}

// Called every frame
void ABuilderNivelAleatorio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderNivelAleatorio::SeleccionarLugarConstruccion(FVector pos1, FVector pos2)
{
	LugarConstruccionInicio = pos1;
    LugarConstruccionFin = pos2;
}

AFabricaDeBloques* Fabrica;

void ABuilderNivelAleatorio::CrearTerreno()
{
    Fabrica = GetWorld()->SpawnActor<AFabricaDeBloques>(AFabricaDeBloques::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);

    // Asegurar que las coordenadas se ordenen correctamente
    float MinX = FMath::Min(LugarConstruccionInicio.X, LugarConstruccionFin.X);
    float MaxX = FMath::Max(LugarConstruccionInicio.X, LugarConstruccionFin.X);
    float MinY = FMath::Min(LugarConstruccionInicio.Y, LugarConstruccionFin.Y);
    float MaxY = FMath::Max(LugarConstruccionInicio.Y, LugarConstruccionFin.Y);

    float Espaciado = 100.0f;
    float AlturaZ = -200.0f; // Terreno a nivel -200

    for (float x = MinX; x <= MaxX; x += Espaciado)
    {
        for (float y = MinY; y <= MaxY; y += Espaciado)
        {
            FVector PosicionBloque(x, y, AlturaZ);
            ABloque* BloqueTerreno = Fabrica->CrearBloque(AFabricaDeBloques::Concreto, PosicionBloque);
            ANivelBomb->Terreno.Add(BloqueTerreno);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Terreno generado correctamente en área seleccionada A-B"));
}



void ABuilderNivelAleatorio::CrearMuros()
{
    // Verificar que tenemos una referencia válida al nivel
    if (!ANivelBomb)
    {
        UE_LOG(LogTemp, Error, TEXT("ANivelBomb no está inicializado"));
        return;
    }

    // Crear la fábrica si no existe
    if (!Fabrica)
    {
        Fabrica = GetWorld()->SpawnActor<AFabricaDeBloques>(
            AFabricaDeBloques::StaticClass(),
            FVector::ZeroVector,
            FRotator::ZeroRotator
        );

        if (!Fabrica)
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo crear la fábrica de bloques"));
            return;
        }
    }

    // Limpiar arrays anteriores
    ANivelBomb->Muros.Empty();
    ANivelBomb->EspaciosEnBlanco.Empty();

    // Calcular límites del área de construcción
    float MinX = FMath::Min(LugarConstruccionInicio.X, LugarConstruccionFin.X);
    float MaxX = FMath::Max(LugarConstruccionInicio.X, LugarConstruccionFin.X);
    float MinY = FMath::Min(LugarConstruccionInicio.Y, LugarConstruccionFin.Y);
    float MaxY = FMath::Max(LugarConstruccionInicio.Y, LugarConstruccionFin.Y);

    const float Espaciado = 100.0f;
    const float AlturaMuro = 0.0f;

    // Calcular número de pasos para validación
    int32 PasosX = FMath::RoundToInt((MaxX - MinX) / Espaciado) + 1;
    int32 PasosY = FMath::RoundToInt((MaxY - MinY) / Espaciado) + 1;

    UE_LOG(LogTemp, Warning, TEXT("Generando cuadrícula: %d x %d posiciones"), PasosX, PasosY);

    // Recorrer la cuadrícula con índices para mejor control
    for (int32 i = 0; i < PasosX; i++)
    {
        for (int32 j = 0; j < PasosY; j++)
        {
            // Calcular posición actual
            float x = MinX + (i * Espaciado);
            float y = MinY + (j * Espaciado);

            // Asegurar que no excedamos los límites debido a precisión de punto flotante
            x = FMath::Min(x, MaxX);
            y = FMath::Min(y, MaxY);

            FVector PosicionActual(x, y, AlturaMuro);

            // Determinar si es borde (primera o última fila/columna)
            bool EsBordeX = (i == 0 || i == PasosX - 1);
            bool EsBordeY = (j == 0 || j == PasosY - 1);
            bool EsBorde = EsBordeX || EsBordeY;

            if (EsBorde)
            {
                // Crear muro en posición de borde
                ABloque* BloqueMuro = Fabrica->CrearBloque(AFabricaDeBloques::Acero, PosicionActual);

                if (BloqueMuro)
                {
                    ANivelBomb->Muros.Add(BloqueMuro);
                    UE_LOG(LogTemp, Verbose, TEXT("Muro creado en: (%f, %f, %f)"), x, y, AlturaMuro);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("No se pudo crear muro en: (%f, %f, %f)"), x, y, AlturaMuro);
                }
            }
            else
            {
                // Guardar espacio interior como espacio en blanco
                ANivelBomb->EspaciosEnBlanco.Add(PosicionActual);
                UE_LOG(LogTemp, Verbose, TEXT("Espacio en blanco registrado en: (%f, %f, %f)"), x, y, AlturaMuro);
            }
        }
    }
}

void ABuilderNivelAleatorio::CrearPuertas(int32 cant_puertas)
{
}


void ABuilderNivelAleatorio::CrearObstaculos(int32 cant_obstaculos)
{
    // Validaciones iniciales
    if (!ANivelBomb)
    {
        UE_LOG(LogTemp, Error, TEXT("ANivelBomb no está inicializado"));
        return;
    }

    if (ANivelBomb->EspaciosEnBlanco.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No hay espacios en blanco disponibles para obstáculos"));
        return;
    }

    if (cant_obstaculos <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Cantidad de obstáculos debe ser mayor a 0"));
        return;
    }

    // Crear la fábrica si no existe
    if (!Fabrica)
    {
        Fabrica = GetWorld()->SpawnActor<AFabricaDeBloques>(
            AFabricaDeBloques::StaticClass(),
            FVector::ZeroVector,
            FRotator::ZeroRotator
        );

        if (!Fabrica)
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo crear la fábrica de bloques"));
            return;
        }
    }

    // Limpiar obstáculos anteriores
    ANivelBomb->Obstaculos.Empty();

    // Ajustar cantidad si excede espacios disponibles
    int32 CantidadFinal = FMath::Min(cant_obstaculos, ANivelBomb->EspaciosEnBlanco.Num());

    UE_LOG(LogTemp, Warning, TEXT("Colocando %d obstáculos de %d espacios disponibles"),
        CantidadFinal, ANivelBomb->EspaciosEnBlanco.Num());

    // **MÉTODO 1: DISTRIBUCIÓN UNIFORME**
    DistribuirObstaculosUniforme(CantidadFinal);

    // **MÉTODO 2: DISTRIBUCIÓN POR SECTORES (alternativo)**
    // DistribuirObstaculosPorSectores(CantidadFinal);

    // **MÉTODO 3: DISTRIBUCIÓN CON SEPARACIÓN MÍNIMA (alternativo)**
    // DistribuirObstaculosConSeparacion(CantidadFinal, 200.0f);
}

void ABuilderNivelAleatorio::DistribuirObstaculosUniforme(int32 CantidadObstaculos)
{
    /*
    if (CantidadObstaculos >= ANivelBomb->EspaciosEnBlanco.Num())
    {
        // Si queremos tantos obstáculos como espacios, colocar en todos
        ColocarObstaculosEnTodos();
        return;
    }
    */
    // Crear una copia de los índices para mezclar
    TArray<int32> IndicesDisponibles;
    for (int32 i = 0; i < ANivelBomb->EspaciosEnBlanco.Num(); i++)
    {
        IndicesDisponibles.Add(i);
    }

    // Mezclar los índices aleatoriamente
    for (int32 i = IndicesDisponibles.Num() - 1; i > 0; i--)
    {
        int32 j = FMath::RandRange(0, i);
        IndicesDisponibles.Swap(i, j);
    }

    // Seleccionar los primeros N índices mezclados
    TArray<int32> IndicesSeleccionados;
    for (int32 i = 0; i < CantidadObstaculos; i++)
    {
        IndicesSeleccionados.Add(IndicesDisponibles[i]);
    }

    // Ordenar de mayor a menor para eliminar sin problemas de índices
    IndicesSeleccionados.Sort([](const int32& A, const int32& B) { return A > B; });

    ABloque* Obstaculo = nullptr;
    // Colocar obstáculos en las posiciones seleccionadas
    int32 ObstaculosColocados = 0;
    for (int32 Indice : IndicesSeleccionados)
    {
        if (Indice >= 0 && Indice < ANivelBomb->EspaciosEnBlanco.Num())
        {
            int32 selec_bloque = FMath::RandRange(1, 9);
            switch (selec_bloque) {
            case 1: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Acero, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 2: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Agua, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 3: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Arena, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 4: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Cesped, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 5: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Concreto, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 6: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Ladrillo, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 7: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Madera, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 8: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Oro, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            case 9: Obstaculo = Fabrica->CrearBloque(AFabricaDeBloques::Roca, ANivelBomb->EspaciosEnBlanco[Indice]); break;
            default: break;
            }
            if (Obstaculo)
            {
                ANivelBomb->Obstaculos.Add(Obstaculo);
                ANivelBomb->EspaciosEnBlanco.RemoveAt(Indice);
                ObstaculosColocados++;

                UE_LOG(LogTemp, Verbose, TEXT("Obstáculo colocado en posición: (%f, %f, %f)"),
                    Obstaculo->GetActorLocation().X,
                    Obstaculo->GetActorLocation().Y,
                    Obstaculo->GetActorLocation().Z);
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Obstáculos colocados: %d/%d"), ObstaculosColocados, CantidadObstaculos);
}

void ABuilderNivelAleatorio::CrearEscondites(int32 cant_escondites)
{
}

void ABuilderNivelAleatorio::ColocarEnemigos(int32 cant_enemigos)
{
}

ANivelBomberman* ABuilderNivelAleatorio::ObtenerNivel()
{
    if (ANivelBomb) 
    {
        return ANivelBomb;
    }
    return nullptr;
}

