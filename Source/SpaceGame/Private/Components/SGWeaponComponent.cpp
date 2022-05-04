#include "Components/SGWeaponComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"


USGWeaponComponent::USGWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void USGWeaponComponent::Fire()
{
	MakeShot();
}

int32 USGWeaponComponent::GetMaxAmountShots() const
{
	return MaxAmountShots;
}

int32 USGWeaponComponent::GetCurrentAmountShots() const
{
	return CurrentAmountShots;
}

void USGWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USGWeaponComponent::MakeShot()
{
	if (!GetWorld())
		return;

	if (!GetOwner())
		return;

	// ������/���������� ������� ����������� 
	if (CurrentAmountShots == MaxAmountShots)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Shots reload %d"), CurrentAmountShots);
		if (GetOwner()->GetWorldTimerManager().IsTimerActive(ReloadTimerHandle))
		{
			GetOwner()->GetWorldTimerManager().PauseTimer(ReloadTimerHandle);
		}
		else
		{
			GetOwner()->GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &USGWeaponComponent::ReloadBlaster, TimeReload, true);
		}
	}
	else if (CurrentAmountShots <= 0)
	{
		return;
	}

	// ��������� ���� ��������� ����������� 
	ACharacter* CharacterOwner = Cast<ACharacter>(GetOwner());
	if (!CharacterOwner)
		return;
	USkeletalMeshComponent* CharacterMesh = CharacterOwner->GetMesh();
	if (!CharacterMesh)
		return;	

	// ��������� ������� ���� 
	const FTransform LeftBlasterSocketTransform = CharacterMesh->GetSocketTransform("LeftBlasterSocket");
	const FTransform RightBlasterSocketTransform = CharacterMesh->GetSocketTransform("RightBlasterSocket");
	// ����������� ���� ��� ���� ��������� 
	const FVector LeftBlasterShotDirection = LeftBlasterSocketTransform.GetRotation().GetForwardVector();
	const FVector RightBlasterShotDirection = RightBlasterSocketTransform.GetRotation().GetForwardVector();
	const FVector LeftBlasterTraceStart = LeftBlasterSocketTransform.GetLocation();
	const FVector RightBlasterTraceStart = RightBlasterSocketTransform.GetLocation();
	const FVector LeftBlasterTraceEnd = LeftBlasterTraceStart+ LeftBlasterShotDirection *TraceMaxDistance;
	const FVector RightBlasterTraceEnd = RightBlasterTraceStart+ RightBlasterShotDirection *TraceMaxDistance;
	// ��������� ����������
	DrawDebugLine(GetWorld(), LeftBlasterTraceStart, LeftBlasterTraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	DrawDebugLine(GetWorld(), RightBlasterTraceStart, RightBlasterTraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	
	FHitResult HitLeftResult, HitRightResult;
	GetWorld()->LineTraceSingleByChannel(HitLeftResult, LeftBlasterTraceStart, LeftBlasterTraceEnd, ECollisionChannel::ECC_Visibility);
	GetWorld()->LineTraceSingleByChannel(HitRightResult, RightBlasterTraceStart, RightBlasterTraceEnd, ECollisionChannel::ECC_Visibility);

	// ����������� �������� �� ������� ��� ������� ����  
	if (HitLeftResult.bBlockingHit)
	{
		DrawDebugSphere(GetWorld(), HitLeftResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
		auto HitActor = HitLeftResult.GetActor();
		if (HitActor)
			HitActor->Destroy();
	}
	if (HitRightResult.bBlockingHit)
	{
		DrawDebugSphere(GetWorld(), HitRightResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
		auto HitActor = HitRightResult.GetActor();
		if (HitActor)
			HitActor->Destroy();
	}
	// ���������� ��������� 
	if (CurrentAmountShots - 2 >= 0)
		CurrentAmountShots--;
}

void USGWeaponComponent::ReloadBlaster()
{
	if(CurrentAmountShots+1 <= MaxAmountShots)
		CurrentAmountShots++;

	if (CurrentAmountShots == MaxAmountShots && GetOwner()->GetWorldTimerManager().IsTimerActive(ReloadTimerHandle))
	{
		GetOwner()->GetWorldTimerManager().PauseTimer(ReloadTimerHandle);
	}
}