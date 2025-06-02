#include "Patterns/Singleton_Main.h"
#include "Patterns/Inventory.h"
#include "Patterns/Puntuacion.h"
// Sets default values
ASingleton_Main::ASingleton_Main()
{
    // Set this actor to call Tick() every frame.  
        PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void ASingleton_Main::BeginPlay()
{
    Super::BeginPlay();
    //Create 4 Inventory
    for (int i = 0; i <= 4; i++)
    {
        AInventory* SpawnedInventory = GetWorld()->SpawnActor<AInventory>(AInventory::StaticClass());
        if (SpawnedInventory)
        {
            //If the Spawn succeeds, set the Spawned inventory to the local one
            Inventory = SpawnedInventory;
            GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s has been created"), *Inventory->GetName()));
        }
    }
    for (int j = 0; j <= 3; j++)
    {
        APuntuacion* PuntuacionSpawneada = GetWorld()->SpawnActor<APuntuacion>(APuntuacion::StaticClass());
        if (PuntuacionSpawneada)
        {
            Puntuacion = PuntuacionSpawneada;
        }
    }
}
// Called every frame
void ASingleton_Main::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
