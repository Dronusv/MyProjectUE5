// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;

}

void AMyPlayerController::BeginSpectatingState()
{
	SetControlRotation(FRotator(-75.0f, 0.0f, 0.0f));
	Super::BeginSpectatingState();
}