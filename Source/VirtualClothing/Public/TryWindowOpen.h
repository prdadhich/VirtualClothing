// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "TextureActor.h"
#include "HAL/FileManager.h"

#include "TryWindowOpen.generated.h"

UCLASS()
class ATryWindowOpen : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATryWindowOpen();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintImplementableEvent)
		void Open();


	UFUNCTION(BlueprintCallable, Category = "FilePicker")
	void OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, TArray<FString>& OutFileNames, FString& OutFilePath);

	UFUNCTION(BlueprintCallable, Category = "FilePicker")
	void PrintData(const FString& File);
	
	

	

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString ImageUrl;



private: 
	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);
	void MoveRight(float AxisValue);
	void LookRight(float AxisValue);
	

};
