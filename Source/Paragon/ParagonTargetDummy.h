// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonCharacter.h"
#include "ParagonTargetDummy.generated.h"

class UTextRenderComponent;

UCLASS()
class PARAGON_API AParagonTargetDummy : public AParagonCharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParagonTargetDummy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Text render component - used instead of UMG, to keep the tutorial short */
	UPROPERTY(VisibleAnywhere)
	UTextRenderComponent* CharText;

public:	
	/** Marks the properties we wish to replicate */
	//virtual void GetLif etimeReplicat edProps(TArray <FLifetimePro perty>& OutLifetim eProps) c onst over ride;

	/** Applies damage to the character */
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	/** Updates the character's text to match with the updated stats */
	void UpdateCharText();

private:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Health, Category = "Stats")
	float DummyHealth;

	/** Called when the Health variable gets updated */
	UFUNCTION()
	void OnRep_Health();
};
