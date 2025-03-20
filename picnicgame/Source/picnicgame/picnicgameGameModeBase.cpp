// Copyright Epic Games, Inc. All Rights Reserved.


#include "picnicgameGameModeBase.h"
#include "System/PicnicHUD.h"

ApicnicgameGameModeBase::ApicnicgameGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	HUDClass = APicnicHUD::StaticClass();
}

void ApicnicgameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}
