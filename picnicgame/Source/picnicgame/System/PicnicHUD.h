#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PicnicHUD.generated.h"

class UTutorialWidget;
class UTraitSelectorWidget;
class UColorSelectorWidget;
class UCharacterCreatorWidget;
class USaveLoadWidget;
class USettingsWidget;

UCLASS()
class APicnicHUD : public AHUD
{
	GENERATED_BODY()

public:

	// FUNCTIONS
	// -----------------------------

	APicnicHUD();
	
	virtual void BeginPlay() override;

	// PROPERTIES & VARIABLES
	// -----------------------------

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<USaveLoadWidget> SaveLoadWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<USettingsWidget> SettingsWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UCharacterCreatorWidget> CharacterCreatorWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UColorSelectorWidget> ColorSelectorWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UTraitSelectorWidget> TraitSelectorWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UTutorialWidget> TutorialWidgetClass;

protected:
	
	// PROPERTIES & VARIABLES
	// -----------------------------

	UPROPERTY()
	USaveLoadWidget* SaveLoadWidget;

	UPROPERTY()
	USettingsWidget* SettingsWidget;

	UPROPERTY()
	UCharacterCreatorWidget* CharacterCreatorWidget;

	UPROPERTY()
	UColorSelectorWidget* ColorSelectorWidget;

	UPROPERTY()
	UTraitSelectorWidget* TraitSelectorWidget;

	UPROPERTY()
	UTutorialWidget* TutorialWidget;
	
};
