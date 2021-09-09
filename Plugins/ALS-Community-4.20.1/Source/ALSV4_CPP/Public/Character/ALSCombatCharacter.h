// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "Character/ALSCharacter.h"
#include "ALSCombatCharacter.generated.h"


/**
 * 
 */
UCLASS()
class ALSV4_CPP_API AALSCombatCharacter : public AALSCharacter, public IAbilitySystemInterface
{

	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
public:
	// UPROPERTY(BlueprintReadWrite, Category = "ALS|Movement System")

	// Implement in BP to get Attack Anim They want
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ALS|Ragdoll System")
	UAnimMontage* GetAttackAnimation(bool bRagdollFaceUpState);

	// UGameplayAbility* AbilitySysComp;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="ALS|GAS", meta=(AllowPrivateAccess="true"))
	UAbilitySystemComponent* AbilitySysComp;
	

};
