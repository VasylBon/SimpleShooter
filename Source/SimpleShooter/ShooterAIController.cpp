// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay() 
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
	}
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (LineOfSightTo(PlayerPawn))
	{
		SetFocus(PlayerPawn, EAIFocusPriority::Default);
		MoveToActor(PlayerPawn, AcceptanceDistance);
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}

	
}