// Fill out your copyright notice in the Description page of Project Settings.

#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "TextureActor.h"
#include "Components/InputComponent.h"
#include "TryWindowOpen.h"

// Sets default values
ATryWindowOpen::ATryWindowOpen()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATryWindowOpen::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATryWindowOpen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATryWindowOpen::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATryWindowOpen::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ATryWindowOpen::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATryWindowOpen::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ATryWindowOpen::LookRight);

}



void ATryWindowOpen::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ATryWindowOpen::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void ATryWindowOpen::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ATryWindowOpen::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void ATryWindowOpen::OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, TArray<FString>& OutFileNames, FString& OutFilePath)
{
	if (GEngine)
	{
		if (GEngine->GameViewport)
		{
			void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
			IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
			
			if (DesktopPlatform)
			{
				//Opening the file picker!
				uint32 SelectionFlag = 0; //A value of 0 represents single file selection while a value of 1 represents multiple file selection
				DesktopPlatform->OpenFileDialog(ParentWindowHandle, DialogTitle, DefaultPath, FString(""), FileTypes, SelectionFlag, OutFileNames);
				

				OutFilePath = FileManager.ConvertToAbsolutePathForExternalAppForRead(*OutFileNames[0]);
				if (OutFilePath!= "")
				{
					ImageUrl = OutFilePath;
				
					
					
				}
			}
		}
	}


}

void ATryWindowOpen::PrintData(const FString& File)
{

	TArray<FString> LoadedText;
	FFileHelper::LoadFileToStringArray(LoadedText, *File);
	//Print the contents
	for (int32 i = 0; i < LoadedText.Num(); i++)
	{
		GLog->Log(LoadedText[i]);
	}
}

