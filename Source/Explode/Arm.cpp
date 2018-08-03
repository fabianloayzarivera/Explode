// Fill out your copyright notice in the Description page of Project Settings.

#include "Arm.h"


// Sets default values
AArm::AArm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	ArmMesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(TEXT("Arm Mesh"));	
	if (ArmMesh)
	{
		ArmMesh->SetupAttachment(RootComponent);
	}
	SpawnSphere = CreateOptionalDefaultSubobject<USphereComponent>(TEXT("Spawn Sphere"));
	if (SpawnSphere)
		SpawnSphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AArm::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AArm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArm::Shoot(float _ProjectileDamage)
{
	check(0 && "You must override this");
}


void AArm::FirePressed()
{
	check(0 && "You must override this");
}

void AArm::FireReleased()
{
	check(0 && "You must override this");
}

void AArm::Init(AExplodeCharacter * _Owner)
{
	this->PlayerRef = _Owner;
}