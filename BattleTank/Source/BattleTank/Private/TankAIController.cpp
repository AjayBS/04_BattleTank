// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	// TODO Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);
	// Aim towards the player	
	auto AImingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AImingComponent->AimAt(PlayerTank->GetActorLocation());
	//ControlledTank->Fire(); // TODO limit firing rate
	
}

