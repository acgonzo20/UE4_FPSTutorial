// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera\CameraComponent.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"


UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Handes input for moving forward and backward
	UFUNCTION()
		void MoveForward(float Value);
	//Handles input for moving left and right
	UFUNCTION()
		void MoveRight(float Value);

	//Sets jump flag when key is pressed
	UFUNCTION()
		void StartJump();
	//Clears jump flag when is released
	UFUNCTION()
		void StopJump();
	UFUNCTION()
		void Fire();

	//FPS Camera
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;

	//First-person mesh (arms), visible only to the owning player
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;

	//Gun muzzle's offset from the camera location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;

	//Projectile class to spawn
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

};
