// Fill out your copyright notice in the Description page of Project Settings.

#include "TryWindowOpen.h"
#include "TextureActor.h"

// Sets default values
ATextureActor::ATextureActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	RootComponent = Plane;

}

// Called when the game starts or when spawned
void ATextureActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATextureActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATextureActor::DownloadImage(FString url)
{

	DownloadUrl = url;
}

