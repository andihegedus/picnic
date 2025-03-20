#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "PCharacter.generated.h"

class APicnicHUD;
class APController;

UCLASS()
class PICNICGAME_API APCharacter: public ACharacter
{
	GENERATED_BODY()
	
public:
	// FUNCTIONS
	// -----------------------------

	APCharacter();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// PROPERTIES & VARIABLES
	// -----------------------------
	
	UPROPERTY()
	APController* PlayerController;
	
	UPROPERTY(EditAnywhere)
	APicnicHUD* HUD;
};
