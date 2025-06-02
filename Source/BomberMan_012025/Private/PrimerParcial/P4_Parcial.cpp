// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimerParcial/P4_Parcial.h"
#include "TimerManager.h"

AP4_Parcial::AP4_Parcial()
{
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialP4(TEXT("Material'/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean'"));
	if (MaterialP4.Succeeded())
	{
		MallaBloque->SetMaterial(0, MaterialP4.Object);
	}
}

void AP4_Parcial::BeginPlay()
{
	//Si toca 1 horizontal si toca 2 vertical
	mov = FMath::RandRange(1, 2);
	//Se establece a cada cuanto tiempo ejecuta un movimiento el bloque.
	GetWorldTimerManager().SetTimer(TimerNewMov, this, &AP4_Parcial::new_mov, mov_time,true);
}

void AP4_Parcial::new_mov()
{
	old_pos = GetActorLocation();
	if(mov==1)
	{ 
		//Si toca 1 izquierda y si toca 2 derecha
		int izq_der=FMath::RandRange(1,2);
		if (izq_der == 1)
		{
			SetActorLocation(GetActorLocation()+FVector(100.0f,0.0f,0.0f));
			//Usamos esta funcion para regresar a su posicion anterior en la mitad de tiempo.
			GetWorldTimerManager().SetTimer(TimerOldMov, this, &AP4_Parcial::old_mov, mov_time / 2, false);
		}
		else
		{
			SetActorLocation(GetActorLocation() + FVector(-100.0f, 0.0f, 0.0f));
			GetWorldTimerManager().SetTimer(TimerOldMov, this, &AP4_Parcial::old_mov, mov_time / 2, false);
		}
	}
	else
	{
		//Si toca 1 arriba y si toca 2 abajo
		int arr_aba = FMath::RandRange(1,2);
		if (arr_aba == 1)
		{
			SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 100.0f));
			GetWorldTimerManager().SetTimer(TimerOldMov, this, &AP4_Parcial::old_mov, mov_time / 2, false);
		}
		else
		{
			SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, -100.0f));
			GetWorldTimerManager().SetTimer(TimerOldMov, this, &AP4_Parcial::old_mov, mov_time / 2, false);
		}
	}
}

void AP4_Parcial::old_mov() { SetActorLocation(old_pos); }


