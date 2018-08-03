// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Arm.h"
#include "Pistol.generated.h"

/**
 * 
 */
UCLASS()
class EXPLODE_API APistol : public AArm
{
	GENERATED_BODY()
	
public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void Shoot(float _ProjectileDamage) override;
	
	UFUNCTION(BlueprintCallable)
		virtual void Init(AExplodeCharacter* _Owner) override;

	UFUNCTION(BlueprintCallable)
		virtual void FirePressed() override;

	UFUNCTION(BlueprintCallable)
		virtual void FireReleased() override;

protected:
	virtual void BeginPlay() override;
};
