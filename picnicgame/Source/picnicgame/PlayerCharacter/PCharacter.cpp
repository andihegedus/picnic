#include "PCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "picnicgame/PicnicGameInstance.h"
#include "picnicgame/System/PicnicHUD.h"

APCharacter::APCharacter()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(GetRootComponent());
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

	SpringArmComp->TargetArmLength = 0.f;
	SpringArmComp->bEnableCameraLag = false;
	SpringArmComp->bUsePawnControlRotation = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	LineTraceStart = {FVector::ZeroVector};
	CheckInteractionDistance = 400.f;
}

void APCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APCharacter::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<APicnicHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

	GameInstance = Cast<UPicnicGameInstance>(GetWorld()->GetGameInstance());

	CheckForInteractable();
}

void APCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	APController* PlayerBaseController = CastChecked<APController>(Controller);

	check(EnhancedInputComponent && PlayerBaseController);

	EnhancedInputComponent->BindAction(PlayerBaseController->EscapeAction, ETriggerEvent::Completed, this, &APCharacter::OpenCloseWidget);
	
	ULocalPlayer* LocalPlayer = PlayerBaseController->GetLocalPlayer();

	check(LocalPlayer);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	check(Subsystem);
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(PlayerBaseController->PCMappingContext, 0);
}

void APCharacter::OpenCloseWidget()
{
	//TBD
}

void APCharacter::CheckForInteractable()
{
	LineTraceStart = CameraComp->GetComponentLocation();
	
	FVector LineTraceEnd{LineTraceStart + (CameraComp->GetComponentRotation().Vector() * CheckInteractionDistance)};
	float LookDirection = FVector::DotProduct(GetActorForwardVector(), CameraComp->GetComponentRotation().Vector());

	if (LookDirection > 0)
	{
		// Visualize the trace hit line
		DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Magenta, false, 1.0f, 0, 2.f);

		FCollisionQueryParams QueryParams;

		QueryParams.AddIgnoredActor(this);

		FHitResult TraceHit;

		if(GetWorld()->LineTraceSingleByChannel(TraceHit, LineTraceStart, LineTraceEnd, ECC_Visibility, QueryParams))
		{
		}
	}
}
