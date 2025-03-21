#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterCreatorWidget.generated.h"

class APCharacter;
class APController;
class UPicnicGameInstance;
class UButton;
class UBorder;

UCLASS()
class PICNICGAME_API UCharacterCreatorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// FUNCTIONS
	// -----------------------------
	void UpdateWidget();

	// PROPERTIES & VARIABLES
	// -----------------------------

	UPROPERTY()
	APCharacter* PlayerCharacter;

	UPROPERTY()
	APController* PlayerController;

	UPROPERTY()
	UPicnicGameInstance* GameInstance;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* DesignModeButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* PictureModeButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* SaveButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* SettingsButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* BodyButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* ClothesButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* EyesButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UButton* MouthButton;
	

protected:
	// FUNCTIONS
	// -----------------------------

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;


	// PROPERTIES & VARIABLES
	// -----------------------------
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UBorder* SaveSettingsBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UBorder* PlayModeBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UBorder* ColorSelectorBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UBorder* TraitSelectorBorder;
};
