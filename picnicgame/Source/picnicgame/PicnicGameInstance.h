#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PicnicGameInstance.generated.h"

class USaveData;

UCLASS()
class PICNICGAME_API UPicnicGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// FUNCTIONS
	// -----------------------------

	UPicnicGameInstance();
	
	virtual void Init() override;
	
	void CreateSaveFile();

	void SaveGame();

	void LoadGame();

	// PROPERTIES & VARIABLES
	// -----------------------------
	
	UPROPERTY()
	USaveData* GameSaveInstance;
	
	
};
