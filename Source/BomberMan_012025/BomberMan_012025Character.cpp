// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025Character.h"
//SHIELD
#include "Prototypes/Shield/Shield.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Kismet/GameplayStatics.h"
#include "BomberMan_012025GameMode.h"  // Asegúrate de incluir tu GameMode
DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ABomberMan_012025Character

ABomberMan_012025Character::ABomberMan_012025Character()
{
	SetActorScale3D(FVector(1.0f,1.0f,1.0f));
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

//Agregando para la bomba con CHATGPT
void ABomberMan_012025Character::BeginPlay()
{
	{
		Super::BeginPlay();
		/*Codigo para verificar que un mapping context ha sido agregado
		APlayerController* PC = Cast<APlayerController>(GetController());
		if (PC)
		{
			ULocalPlayer* LocalPlayer = PC->GetLocalPlayer();
			if (LocalPlayer)
			{
				UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
				if (Subsystem && DefaultMappingContext)
				{
					GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Black, TEXT("Mapping agregado"));
					Subsystem->AddMappingContext(DefaultMappingContext, 0);
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Black, TEXT("No se agrego el mapping"));
				}
			}
		}
		*/
	}
}
void ABomberMan_012025Character::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ABomberMan_012025Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABomberMan_012025Character::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABomberMan_012025Character::Look);

		if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
		{
			EnhancedInput->BindAction(ColocarBombaAction, ETriggerEvent::Triggered, this, &ABomberMan_012025Character::ColocarBomba);
		}

		if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
		{
			EnhancedInput->BindAction(DashAction, ETriggerEvent::Triggered, this, &ABomberMan_012025Character::DashPJ);
		}

		if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
		{
			EnhancedInput->BindAction(ShieldAction, ETriggerEvent::Triggered, this, &ABomberMan_012025Character::ShieldPJ);
		}
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ABomberMan_012025Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABomberMan_012025Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}


void ABomberMan_012025Character::ColocarBomba()
{
	if(CantBombas>0){
		GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Black, TEXT("Has llamado a la accion de colocar bomba."));
		ABomberMan_012025GameMode* GameMode = Cast<ABomberMan_012025GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GameMode)
		{
			GameMode->SpawnBomba();
			CantBombas--;
			//Recargar bomba con tiempo
			GetWorld()->GetTimerManager().SetTimer(RecargaBomba, this, &ABomberMan_012025Character::RecargarBomba, 4.4f, false);
		}
	}
}

void ABomberMan_012025Character::RecargarBomba()
{
	if (CantBombas < CantBombas+1) {
		CantBombas++;
		GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Yellow, TEXT("Se ha recargado la bomba."));
	}
}

void ABomberMan_012025Character::DashPJ()
{
	if (DashCooldown > 0)
	{
		// Ejecutar la animación durante el dash (0.2 segundos)
		UAnimSequence* DashAnim = LoadObject<UAnimSequence>(nullptr, TEXT("/Script/Engine.AnimSequence'/Game/Characters/Mannequins/Animations/Manny/SKM_Robot.SKM_Robot'"));
		if (DashAnim)
		{
			GetMesh()->PlayAnimation(DashAnim, false); // false = no se repite
		}
		GetCharacterMovement()->MaxWalkSpeed = 5000.0f;
		GetCharacterMovement()->MaxAcceleration = 10000.0f;
		DashCooldown--;
		//Volver a velocidad por defecto
		GetWorld()->GetTimerManager().SetTimer(SetDefaultSpeed, this, &ABomberMan_012025Character::set_defaultSpeed, duracionDash, false);
		//Recargar Dash con tiempo
		GetWorld()->GetTimerManager().SetTimer(THRecargaDash, this, &ABomberMan_012025Character::RecargarDash, 5.0f, false);
	}
}

void ABomberMan_012025Character::set_defaultSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	GetCharacterMovement()->MaxAcceleration = 2048.0f;
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, TEXT("Se ha vuelto a la velocidad por defecto."));

	// Restaurar control por Anim Blueprint
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
}

void ABomberMan_012025Character::RecargarDash()
{
	if (DashCooldown < 1)
	{
		DashCooldown++;
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Blue, TEXT("Se ha recargado el Dash."));
	}
}

void ABomberMan_012025Character::ShieldPJ()
{
	if(ShieldItems>0)
	{ 
		Shield=GetWorld()->SpawnActor<AShield>(AShield::StaticClass(), GetActorLocation(), GetActorRotation());
		ShieldItems--;
		GetWorld()->GetTimerManager().SetTimer(THReloadShield, this, &ABomberMan_012025Character::ReloadShield, ShieldCooldown, false);
		GetWorld()->GetTimerManager().SetTimer(THShieldEffect, this, &ABomberMan_012025Character::EndShield, ShieldTime, false);
	}
}

void ABomberMan_012025Character::EndShield()
{
	Shield->Destroy();
}

void ABomberMan_012025Character::ReloadShield()
{
	if (ShieldItems < 1)
	{
		ShieldItems++;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, TEXT("SHIELD RELOADED."));
	}
}
