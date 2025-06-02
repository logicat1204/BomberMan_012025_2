#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Singleton_Main.generated.h"
UCLASS()
class BOMBERMAN_012025_API ASingleton_Main : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ASingleton_Main();
private:
	//The Inventory of this Actor
	UPROPERTY()
	class AInventory* Inventory;
	UPROPERTY()
	class APuntuacion* Puntuacion;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};