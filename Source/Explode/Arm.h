// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Arm.generated.h"

class AExplodeCharacter;
class AProjectile;
UCLASS()
class EXPLODE_API AArm : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		USkeletalMeshComponent* ArmMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		USphereComponent* SpawnSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		float ProjectileDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		int32 Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		int32 Magazine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		float Range;

	UPROPERTY(VisibleAnywhere)
		AExplodeCharacter* PlayerRef;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void Shoot(float _ProjectileDamage);

	UFUNCTION(BlueprintCallable)
		virtual void FirePressed();

	UFUNCTION(BlueprintCallable)
		virtual void FireReleased();

	UFUNCTION(BlueprintCallable)
		virtual void Init(AExplodeCharacter* _Owner);
	
};
