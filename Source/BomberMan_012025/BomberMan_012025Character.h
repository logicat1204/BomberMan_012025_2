// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "BomberMan_012025Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABomberMan_012025Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ColocarBombaAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ShieldAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* DashAction;
	int32 DashCooldown = 1;
	int32 DefaultSpeed = 600.0f;
	FTimerHandle SetDefaultSpeed;
	FTimerHandle THRecargaDash;
	float duracionDash=0.06f;

public:
	//Para mecanica colocar bomba
	UPROPERTY(EditAnywhere, Category = "Bomb")
	int32 CantBombas=1;
	FTimerHandle RecargaBomba;

	UPROPERTY(EditAnywhere, Category = "Shield")
	AActor* Shield;
	int32 ShieldItems=1;
	FTimerHandle THReloadShield;
	FTimerHandle THShieldEffect;
	float ShieldTime=0.5f;
	float ShieldCooldown=5.0f;

public:
	ABomberMan_012025Character();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);


			

protected:
	//agregado para la bomba
	void BeginPlay();

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }



protected:
	// Función que manejará la acción de colocar la bomba
	void ColocarBomba();
	//Funcion que recarga el uso de bombas
	void RecargarBomba();
	void RecargarDash();
	//Funcion para incrementar el movimiento del personaje por un momento(Dash)
	void DashPJ();
	void set_defaultSpeed();

	void ShieldPJ();
	void EndShield();
	void ReloadShield();
};

