#include "Player/SGBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SGWeaponComponent.h"
#include "SpaceGame/SpaceGameGameModeBase.h"

ASGBaseCharacter::ASGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());

	WeaponComponent = CreateDefaultSubobject<USGWeaponComponent>("WeaponComponent");

	OnTakeAnyDamage.AddDynamic(this, &ASGBaseCharacter::OnTakeDamage);
}

void ASGBaseCharacter::MoveRight(float Amount)
{
	USkeletalMeshComponent* CharacterMesh = GetMesh();

	if (CharacterMesh) {
		FRotator NewMeshRotation = CharacterMesh->GetRelativeRotation();

		if (Amount > 0.0) {
			NewMeshRotation.Pitch = 20.0f;
		}
		else if (Amount < 0.0)
		{
			NewMeshRotation.Pitch = -20.0f;
		}
		else
		{
			NewMeshRotation.Pitch = 0.0f;
		}
		CharacterMesh->SetRelativeRotation(NewMeshRotation);
	}
	AddMovementInput(GetActorRightVector(), Amount);
}

void ASGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	// установка персонажа в режим полета 
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		MovementComponent->SetMovementMode(EMovementMode::MOVE_Flying);
	}
}

void ASGBaseCharacter::OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	// скрытие актора, остановка управления 
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
	DisableInput(nullptr);

	// завершение игры 
	if (GetWorld())
	{
		if (const auto GameMode = Cast<ASpaceGameGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->GameOver();
		}
	}
}

void ASGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	check(WeaponComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASGBaseCharacter::MoveRight);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &USGWeaponComponent::Fire);
}

