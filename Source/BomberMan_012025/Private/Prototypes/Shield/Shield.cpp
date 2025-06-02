// Fill out your copyright notice in the Description page of Project Settings.
#include "Prototypes/Shield/Shield.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AShield::AShield()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShieldCapsule = CreateDefaultSubobject<UCapsuleComponent>("ShieldCapsule");
	ShieldCapsule->InitCapsuleSize(102.f, 150.f);


	ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>("ShieldMesh");
	RootComponent = ShieldCapsule;
	ShieldMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShieldAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (ShieldAsset.Succeeded()) {
		ShieldMesh->SetStaticMesh(ShieldAsset.Object);
		ShieldMesh->SetRelativeScale3D(FVector(2.5f, 2.5f, 2.5f));
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> M_ShieldAsset(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/StarterContent/Materials/M_Shield.M_Shield'"));
	if (M_ShieldAsset.Succeeded()) {
		ShieldMesh->SetMaterial(0,M_ShieldAsset.Object);
	}

	ShieldCapsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ShieldCapsule->SetCollisionObjectType(ECC_WorldDynamic);
	ShieldCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);     // Ignora todo por defecto

	// Colisiona solo con lo que te interesa:
	ShieldCapsule->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);       // Detecta enemigos (si son Pawns)
	ShieldCapsule->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block); // Bloquea explosiones, etc
	ShieldCapsule->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);      // Ignora la cámara
	ShieldCapsule->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);  // Ignora trazos de visibilidad
}

// Called when the game starts or when spawned
void AShield::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (MyCharacter)
	{
		// Adjuntar al componente raíz (o a un socket si quieres)
		AttachToComponent(MyCharacter->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

		// Posicionar justo delante o debajo del jugador, si es necesario
		SetActorRelativeLocation(FVector(0.0f, 0.0f, -100.0f));
	}
}

// Called every frame
void AShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

