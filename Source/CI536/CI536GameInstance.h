// Copyright © 2020 Jack C. Lloyd.

#pragma once

#pragma region INCLUDES

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CI536Pad.h"
#include "CI536GameInstance.generated.h"

#pragma endregion

#pragma region CLASSES

/**
 * Game Instance.
 */
UCLASS()
class CI536_API UCI536GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/* The number of players (i.e., non-artificial intelligence). */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		int PlayerControllerCount = 4; // Reminder: change to 1.

	/* Set the number of players (i.e., non-artificial intelligence). */
	UFUNCTION(BlueprintCallable)
		int SetPlayerControllerCount(int Count);
};

#pragma endregion