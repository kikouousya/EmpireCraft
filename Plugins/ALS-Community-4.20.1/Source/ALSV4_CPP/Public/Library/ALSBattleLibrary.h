#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Library/ALSCharacterEnumLibrary.h"
#include "ALSBattleLibrary.generated.h"

class UCurveVector;
class UAnimMontage;
class UAnimSequenceBase;
class UCurveFloat;
class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FALSSkill
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Character Struct Library")
		FTransform Transform;

	UPROPERTY(EditAnywhere, Category = "Character Struct Library")
		class UPrimitiveComponent* Component = nullptr;
};

USTRUCT()
struct FALSAttack
{
	GENERATED_BODY()
	
};
