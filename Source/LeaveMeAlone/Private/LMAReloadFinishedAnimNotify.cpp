// Fill out your copyright notice in the Description page of Project Settings.


#include "LMAReloadFinishedAnimNotify.h"


void ULMAReloadFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	OnNotifyReloadFinished.Broadcast(MeshComp);
    Super::Notify(MeshComp, Animation);
}