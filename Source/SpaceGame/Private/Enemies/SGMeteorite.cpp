#include "Enemies/SGMeteorite.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"


ASGMeteorite::ASGMeteorite()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");

	OnActorBeginOverlap.AddDynamic(this, &ASGMeteorite::OnBeginOverllap);
}

void ASGMeteorite::BeginPlay()
{
	Super::BeginPlay();
}

void ASGMeteorite::OnConstruction(const FTransform& Transform)
{
	// рандомное изменение масштаб метеорита при создание 
	FVector NewScale3D = FVector(1.0f, 1.0f, 1.0f) * FMath::RandRange(MinScaleMeteorite, MaxScaleMeteorite);
	SetActorScale3D(NewScale3D);

	// установка рандомыного вращения 
	if (RotatingMovementComponent)
	{
		RotatingMovementComponent->RotationRate = UKismetMathLibrary::RandomRotator(true);
	}
}

void ASGMeteorite::OnBeginOverllap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (ASGMeteorite* meteorite = Cast<ASGMeteorite>(OtherActor))
	{
		// если столкновение то увеличение скорости 
		float NewSpeed = meteorite->GetSpeedMeteorite()+(SpeedMeteorite-meteorite->GetSpeedMeteorite())+5.0f;
		meteorite->SetSpeedMeteorite(NewSpeed);
	}
	else
	{
		// нанесение урона игроку
		OtherActor->TakeDamage(10.0f, FDamageEvent(), nullptr, this);
		this->Destroy();
	}
}

void ASGMeteorite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// перемещение актора
	FVector DeltaLocation = DeltaTime*SpeedMeteorite*FVector(-1.0f,0.0f,0.0f);
	AddActorWorldOffset(DeltaLocation);
}

bool ASGMeteorite::Destroy(bool bNetForce, bool bShouldModifyLevel)
{
	bool destored = Super::Destroy(bNetForce, bShouldModifyLevel);
	// play sound explosion
	UGameplayStatics::SpawnSoundAtLocation(GetWorld(),DestroySound, GetActorLocation(), GetActorRotation());
	// spawn destroy effect
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), TraceFX, GetActorLocation());

	return destored;
}

