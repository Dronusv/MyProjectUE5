// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LeaveMeAlone/Public/Components/LMAHealthComponent.h"
#include "MyCharacter.generated.h"



class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;
class ULMAWeaponComponent;

UCLASS()
class LEAVEMEALONE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAWeaponComponent* WeaponComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;
	
	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Zoom")
	float DefaultArmLength = 1400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Zoom")
	float MaxArmLength = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Zoom")
	float MinArmLength = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Zoom")
	float ZoomStep = 10.0f;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;


	// sprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Sprint")
	float SprintSpeed = 600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Sprint")
	float WalkSpeed = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Stamina")
	float MinusStamina = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Stamina")
	float PlusStamina = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Stamina")
	float Stamina = 100.0f;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:

	float YRotation = -75.0f;
	float FOV = 55.0f;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void CameraZoom(float Value);
	void OnDeath();
	void RotationPlayerOnCursor();

	void StartSprint();
	void StopSprint();

	bool bIsSprint;
	
	void DecreaseStamina();
	void IncreaseStamina();

	float CurrentStamina=0.0f;


	void OnHealthChanged(float NewHealth);
};
