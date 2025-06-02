// Fill out your copyright notice in the Description page of Project Settings.
#include "Bloque.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaDeBloques.generated.h"

UCLASS()
class BOMBERMAN_012025_API AFabricaDeBloques : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaDeBloques();
	//Variable de direccion con la que iremos guardando y otra del TArray para guardar los bloques en la clase
	ABloque* BloqueCreado;
	static TArray<ABloque*> aBloques;
	//propieadad de tipo Enum para trabajar con los bloques:
	enum TipoBloque { Aire, Madera, Concreto, Agua , Acero, Cesped, Arena, Ladrillo, Oro, Roca, Vidrio };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual ABloque* CrearBloque(TipoBloque tipo, FVector posicionColocar);
	virtual TArray<ABloque*> GetBloques();
};
