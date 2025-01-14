// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Character::RemovePickup()
{
	auto temp = UGameplayStatics::GetPlayerCameraManager(this, 0);
	auto CameraLocation = temp->GetCameraLocation();
	auto End = temp->GetCameraLocation() + (temp->GetActorForwardVector() * 50000);
	TArray<AActor*> Ignore;
	FHitResult Hit;
	UKismetSystemLibrary::LineTraceSingle(this, CameraLocation, End, ETraceTypeQuery::TraceTypeQuery1, 0, Ignore, EDrawDebugTrace::ForDuration, Hit, true);
	if (Hit.GetActor())
	{
		if (Cast<ACPP_PickUp>(Hit.GetActor()))
		{
			Hit.GetActor()->Destroy();
			UKismetSystemLibrary::PrintString(this, "Destroyed a pickup");
	  }
	}
}

