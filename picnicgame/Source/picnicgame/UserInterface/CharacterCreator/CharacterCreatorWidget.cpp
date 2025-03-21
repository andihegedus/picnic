#include "CharacterCreatorWidget.h"

#include "picnicgame/PicnicGameInstance.h"
#include "picnicgame/PlayerCharacter/PCharacter.h"
#include "picnicgame/PlayerCharacter/PController.h"

void UCharacterCreatorWidget::UpdateWidget()
{
}

void UCharacterCreatorWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	PlayerCharacter = Cast<APCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerCharacter)
	{
		PlayerController = Cast<APController>(PlayerCharacter->GetWorld()->GetFirstPlayerController());

		GameInstance = Cast<UPicnicGameInstance>(GetWorld()->GetGameInstance());

		if (PlayerController)
		{
			UE_LOG(LogTemp, Warning, TEXT("UPlayerInventoryWidget: PlayerController valid!"));
			PlayerController->bShowMouseCursor = true;
			PlayerController->bEnableClickEvents = true; 
			PlayerController->bEnableMouseOverEvents = true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UPlayerInventoryWidget: PlayerController not valid."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UPlayerInventoryWidget: PlayerCharacter not valid."));
	}
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
