// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorBPPure.h"

// Sets default values
AMyActorBPPure::AMyActorBPPure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorBPPure::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorBPPure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
bool AMyActorBPPure::MeuMetodoPuro(){

	return bMeuBool;

}
bool AMyActorBPPure::MeuMetodoNaoPuro(){

	return bMeuBool;
}

