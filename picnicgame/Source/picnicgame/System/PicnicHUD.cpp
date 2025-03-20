#include "PicnicHUD.h"

#include "picnicgame/UserInterface/CharacterCreator/CharacterCreatorWidget.h"
#include "picnicgame/UserInterface/CharacterCreator/ColorSelectorWidget.h"
#include "picnicgame/UserInterface/CharacterCreator/TraitSelectorWidget.h"
#include "picnicgame/UserInterface/Interaction/TutorialWidget.h"
#include "picnicgame/UserInterface/SaveLoad/SaveLoadWidget.h"
#include "picnicgame/UserInterface/Settings/SettingsWidget.h"

APicnicHUD::APicnicHUD()
{
}

void APicnicHUD::BeginPlay()
{
	Super::BeginPlay();

	if (SaveLoadWidgetClass)
	{
		SaveLoadWidget = CreateWidget<USaveLoadWidget>(GetWorld(), SaveLoadWidgetClass);
		SaveLoadWidget->AddToViewport();
		SaveLoadWidget->SetVisibility(ESlateVisibility::Visible);
	}
	if (SettingsWidgetClass)
	{
		SettingsWidget = CreateWidget<USettingsWidget>(GetWorld(), SettingsWidgetClass);
		SettingsWidget->AddToViewport();
		SettingsWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (CharacterCreatorWidgetClass)
	{
		CharacterCreatorWidget = CreateWidget<UCharacterCreatorWidget>(GetWorld(), CharacterCreatorWidgetClass);
		CharacterCreatorWidget->AddToViewport();
		CharacterCreatorWidget->SetVisibility(ESlateVisibility::Visible);
	}
	if (ColorSelectorWidgetClass)
	{
		ColorSelectorWidget = CreateWidget<UColorSelectorWidget>(GetWorld(), ColorSelectorWidgetClass);
		ColorSelectorWidget->AddToViewport();
		ColorSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (TraitSelectorWidgetClass)
	{
		TraitSelectorWidget = CreateWidget<UTraitSelectorWidget>(GetWorld(), TraitSelectorWidgetClass);
		TraitSelectorWidget->AddToViewport();
		TraitSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (TutorialWidgetClass)
	{
		TutorialWidget = CreateWidget<UTutorialWidget>(GetWorld(), TutorialWidgetClass);
		TutorialWidget->AddToViewport();
		TutorialWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}
