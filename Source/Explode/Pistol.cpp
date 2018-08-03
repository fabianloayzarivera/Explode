// Fill out your copyright notice in the Description page of Project Settings.

#include "Pistol.h"
#include "ExplodeCharacter.h"
#include "Engine.h"
#include "Camera/CameraComponent.h"

void APistol::Shoot(float _ProjectileDamage) 
{
	//Shoot single bullet
	FHitResult* HitResult = new FHitResult();
	FVector SpawnLocation = this->SpawnSphere->GetComponentLocation();
	FVector Direction = PlayerRef->GetFollowCamera()->GetForwardVector();
	Direction.Normalize();
	FVector EndTrace = PlayerRef->GetFollowCamera()->GetComponentLocation() + (Direction * Range);

	FCollisionQueryParams *TraceParams = new FCollisionQueryParams();
	TraceParams->bTraceComplex = true;
	TraceParams->bTraceAsyncScene = true;
	TraceParams->bReturnPhysicalMaterial = true;
	TraceParams->AddIgnoredActor(PlayerRef);
	TraceParams->AddIgnoredActor(this);
	FVector SpawnVector;

	GetWorld()->LineTraceSingleByChannel(*HitResult, PlayerRef->GetFollowCamera()->GetComponentLocation(), EndTrace, ECC_GameTraceChannel1, *TraceParams);
	if (HitResult->bBlockingHit)
	{
		DrawDebugLine(GetWorld(), SpawnLocation, HitResult->ImpactPoint, FColor::Green, false, 5.0f);
		DrawDebugPoint(GetWorld(), HitResult->ImpactPoint, 5.0f, FColor::Blue, false, 5.0f);
		SpawnVector = HitResult->ImpactPoint - SpawnLocation;

	}
	else
	{
		DrawDebugLine(GetWorld(), SpawnLocation, EndTrace, FColor::Red, false, 5.0f);
		SpawnVector = EndTrace - SpawnLocation;
	}

	SpawnVector.Normalize();


}

void APistol::BeginPlay()
{
	Super::BeginPlay();
}

void APistol::Init(AExplodeCharacter* _Owner)
{
	Super::Init(_Owner);
}

void APistol::FirePressed()
{
	Shoot(ProjectileDamage);
}

void APistol::FireReleased()
{
	
}



