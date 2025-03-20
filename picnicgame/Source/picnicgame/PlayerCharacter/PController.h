﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "PController.generated.h"

class USaveData;

UCLASS()
class PICNICGAME_API APController: public APlayerController
{
	GENERATED_BODY()
	
public:
	// FUNCTIONS
	// -----------------------------

	static void SetupKeyMap(UInputMappingContext* InputMappingContext, UInputAction* InputAction,
		FKey Key, bool bNegate, bool bSwizzle, EInputAxisSwizzle SwizzleOrder);

	virtual void SetupInputComponent() override;
	
	// PROPERTIES & VARIABLES
	// -----------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UInputMappingContext* PCMappingContext;
	
};
