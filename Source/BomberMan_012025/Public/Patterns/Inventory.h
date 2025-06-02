#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"
UCLASS()
class BOMBERMAN_012025_API AInventory : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AInventory();
	//The instance of this Class
	UPROPERTY()
	AInventory* Instance;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	int32 cant_dulces=0;
	FTimerHandle TH_showinventorytimer;
	void show_dulces();
};
