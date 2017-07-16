// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovement.h"


void UTankMovement::IntendMoveForward(float Throw) {
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend move forwatd throw: %f"), Throw);
}

