#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "PCharacter.generated.h"

class UPicnicGameInstance;
class APicnicHUD;
class APController;
class USpringArmComponent;
class UCameraComponent;

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

	void OpenCloseWidget();
	
	// PROPERTIES & VARIABLES
	// -----------------------------
	
	UPROPERTY()
	APController* PlayerController;

	UPROPERTY()
	UPicnicGameInstance* GameInstance;
	
	UPROPERTY(EditAnywhere)
	APicnicHUD* HUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera");
	USpringArmComponent* SpringArmComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera");
	UCameraComponent* CameraComp;


protected:
	// FUNCTIONS
	// -----------------------------
	
	void CheckForInteractable();
	

	// PROPERTIES & VARIABLES
	// -----------------------------


	FVector LineTraceStart;

	float CheckInteractionDistance;
};
