// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacter.h"
#include "FPSProject.h"
#include "FPSProjectile.h" //INSTRUCTED TO INCLUDE
#include "Components/CapsuleComponent.h" //COMPILE ERROR??
#include "Components/SkeletalMeshComponent.h"



// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// Attach the camera component to our capsule component.
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());
	// Position the camera slightly above the eyes.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// Allow the pawn to control camera rotation.
	FPSCameraComponent->bUsePawnControlRotation = true;


	//NOT SURE THIS IS ACTUALLY WORKING I CHANGED SOMESETTINGS INSIDE OF UE EDITOR 
	//Create a first person mesh component for the owning player
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	//Only the owning player sees this mesh
	FPSMesh->SetOnlyOwnerSee(true);
	//Attach the FPS mesh to the FPS camera
	FPSMesh->SetupAttachment(FPSCameraComponent);
	//Disable some environemtnal shadowing to preserve the illusion of having a single mesh
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	//The owning player doesn't see the regular (third-person) body mesh
	GetMesh()->SetOwnerNoSee(true);

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Put up a debug message for five seconds. The -1 key value indicates that we will never need to update this message.
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Set up "movement" bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	//Set up "Look" bindings
	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter:: AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);

	//Set up "action" bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);


}

void AFPSCharacter::MoveForward(float Value)
{
	//Find out which way is "forward" and record that the player wants to move that way
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::MoveRight(float Value)
{
	//Find out which way is "right" and record that the player wants to move that way
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::Fire()
{
	//Attempt to fire a projectile
	if (ProjectileClass)
	{
		//Get the camera transform
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		//Transform MuzzleOffset from camera space to world space
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;

		//Skew the aim to be slightly upwards
		MuzzleRotation.Pitch += 10.0f;
		UWorld* World = GetWorld();

		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			//Spawn the projectile at the muzzle
			AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);

			if (Projectile) {

				//Set the projectile's intiial trajectory
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}
