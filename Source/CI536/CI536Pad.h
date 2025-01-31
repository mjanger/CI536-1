// Copyright © 2020 Jack C. Lloyd.

#pragma once

#pragma region INCLUDES

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "CI536Pad.generated.h"

#pragma endregion

#pragma region ENUMS

/**
 * Pad Mode.
 */
UENUM()
enum class ECI536PadMode : uint8
{
	EPAD_MODE_POSITIVE UMETA(DisplayName = "Positive"),
	EPAD_MODE_NEGATIVE UMETA(DisplayName = "Negative"),
	EPAD_MODE_NEUTRAL  UMETA(DisplayName = "Neutral")
};

#pragma endregion

#pragma region CLASSES

/**
 * Pad.
 */
UCLASS()
class CI536_API ACI536Pad : public AActor
{
	GENERATED_BODY()
	
private:
	ACI536Pad();

	bool bIsLocked = false;

private:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	/* The cardinal direction North (Arrow). */
	UPROPERTY()
		UArrowComponent* NorthArrow;

	/* The cardinal direction East (Arrow). */
	UPROPERTY()
		UArrowComponent* EastArrow;

	/* The cardinal direction South (Arrow). */
	UPROPERTY()
		UArrowComponent* SouthArrow;

	/* The cardinal direction West (Arrow). */
	UPROPERTY()
		UArrowComponent* WestArrow;

public:
	virtual void Tick(float DeltaTime) override;

	/* The static mesh to render. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* StaticMesh;

	/* Either an active or passive action. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Action)
		bool active = false;

	/* The pad's action when activated. */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Action)
		ECI536PadMode type = ECI536PadMode::EPAD_MODE_NEUTRAL;

	/* The cardinal direction North (Pad). */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Navigation)
		ACI536Pad* NorthPad = nullptr;

	/* The cardinal direction East (Pad). */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Navigation)
		ACI536Pad* EastPad = nullptr;
	
	/* The cardinal direction South (Pad). */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Navigation)
		ACI536Pad* SouthPad = nullptr;

	/* The cardinal direction West (Pad). */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Navigation)
		ACI536Pad* WestPad = nullptr;

	/* Lock the pad. */
	UFUNCTION(BlueprintCallable)
		void Lock();

	/* Unlock the pad. */
	UFUNCTION(BlueprintCallable)
		void Unlock();

	/* Is the pad locked? */
	UFUNCTION(BlueprintPure)
		bool IsLocked() const;
};

#pragma endregion