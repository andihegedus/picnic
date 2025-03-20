#include "CharacterCreatorWidget.h"

void UCharacterCreatorWidget::UpdateWidget()
{
}

void UCharacterCreatorWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UCharacterCreatorWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCharacterCreatorWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}
