#include "Enemies/SGMeteorite.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"



ASGMeteorite::ASGMeteorite()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");

	OnActorBeginOverlap.AddDynamic(this, &ASGMeteorite::OnBeginOverllap);
}

void ASGMeteorite::BeginPlay()
{
	Super::BeginPlay();
}

void ASGMeteorite::OnConstruction(const FTransform& Transform)
{
	// ��������� ��������� ������� ��������� ��� �������� 
	FVector NewScale3D = FVector(1.0f, 1.0f, 1.0f) * FMath::RandRange(MinScaleMeteorite, MaxScaleMeteorite);
	SetActorScale3D(NewScale3D);

	// ��������� ����������� �������� 
	if (RotatingMovementComponent)
	{
		RotatingMovementComponent->RotationRate = UKismetMathLibrary::RandomRotator(true);
	}
}

void ASGMeteorite::OnBeginOverllap(AActor* OverlappedActor, AActor* OtherActor)
{
	// ��������� ����� ������
	OtherActor->TakeDamage(10.0f, FDamageEvent(), nullptr, this);
	this->Destroy();
}

void ASGMeteorite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ����������� ������
	FVector DeltaLocation = DeltaTime*SpeedMeteorite*FVector(-1.0f,0.0f,0.0f);
	AddActorWorldOffset(DeltaLocation);
}

