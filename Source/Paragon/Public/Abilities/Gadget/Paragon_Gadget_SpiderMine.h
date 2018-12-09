// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paragon_Gadget_SpiderMine.generated.h"

class AParagonExplosionEffect;

UCLASS()
class PARAGON_API AParagon_Gadget_SpiderMine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParagon_Gadget_SpiderMine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION()
	void BotDistance();

	UFUNCTION()
	void Explode();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetAbilityPoint(FVector AbilityPoint) { TargetLocation = AbilityPoint; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileActor)
	class UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileActor)
	class USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = ProjectileActor)
	class USkeletalMeshComponent* SkeletalMeshComponent;

private:
	UPROPERTY()
	FVector InitLocation;

	UPROPERTY()
	FVector TargetLocation;

	UPROPERTY()
	bool bFalling = false;

	UPROPERTY()
	float TargetDistance;

	UPROPERTY()
	FTimerHandle RangeTimerHandle;

	UPROPERTY()
	float FuzeTime = 1.f;

	/** effects for explosion */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
	TSubclassOf<class AParagonExplosionEffect> ExplosionTemplate;
};