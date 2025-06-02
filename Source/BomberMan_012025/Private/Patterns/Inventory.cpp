#include "Patterns/Inventory.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AInventory::AInventory()
{
    // Set this actor to call Tick() every frame.  You can turn this off to
        PrimaryActorTick.bCanEverTick = true;
    //Search for existing Instances of this class
    TArray<AActor*> Instances;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AInventory::StaticClass(), Instances);
    if (Instances.Num() >= 1)
    {
        //If exist at least one of them, set the instance with the first found one
        Instance = Cast<AInventory>(Instances[0]);
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s already exists"), *Instance->GetName()));
        //Then Destroy this Actor
        Destroy();
    }
}
// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
    Super::BeginPlay();
    GetWorldTimerManager().SetTimer(TH_showinventorytimer, this, &AInventory::show_dulces, 5.0f, true);
}
// Called every frame
void AInventory::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AInventory::show_dulces()
{
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Black, FString::Printf(TEXT("Cantidad de dulces recogidos: %d"),cant_dulces));
}
