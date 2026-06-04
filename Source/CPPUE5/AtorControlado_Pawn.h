// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AtorControlado_Pawn.generated.h"


UCLASS()
class CPPUE5_API AAtorControlado_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAtorControlado_Pawn();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros Gerais")
	float Velocidade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros Gerais")
	float VelocidadeDeRotacao;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros Gerais")
	float Altura;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parametros Gerais")
	//identifica se esta vivo ou nao 
	bool isAlive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dados Adicionais")
	//Nome do personagem
	FName Nome;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveVerticalmente(float eixoVertical);

	UFUNCTION()
	void RotacionaEmZ(float eixoHorizontal);

};
