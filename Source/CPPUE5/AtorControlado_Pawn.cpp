// Fill out your copyright notice in the Description page of Project Settings.
#include "AtorControlado_Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"


// Sets default values
AAtorControlado_Pawn::AAtorControlado_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malha Estatica"));
	StaticMesh->SetSimulatePhysics(true);
	RootComponent = StaticMesh;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Minha Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->AddRelativeLocation(FVector(-330, 0, 130));

}

// Called when the game starts or when spawned
void AAtorControlado_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAtorControlado_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAtorControlado_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &AAtorControlado_Pawn::MoveVerticalmente);
	PlayerInputComponent->BindAxis("MouseX", this, &AAtorControlado_Pawn::RotacionaEmZ);

}

void AAtorControlado_Pawn::RotacionaEmZ(float eixoHorizontal)
{

	FRotator RotacaoAtual = GetActorRotation();
	FRotator eixoZ = FRotator::MakeFromEuler(FVector(0.f, 0.f, 1.f));
	SetActorRotation(RotacaoAtual + (eixoZ * eixoHorizontal * VelocidadeDeRotacao));

	
}

void AAtorControlado_Pawn::MoveVerticalmente(float eixoVertical)
{
	FVector PosicaoAtual = GetActorLocation();
	FVector Frente = GetActorForwardVector();
	SetActorLocation(PosicaoAtual + (Frente * eixoVertical * Velocidade));
}

