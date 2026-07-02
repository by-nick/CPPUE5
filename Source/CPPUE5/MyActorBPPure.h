// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorBPPure.generated.h"

UCLASS()
class CPPUE5_API AMyActorBPPure : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorBPPure();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pure")
	bool bMeuBool;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Pure")
	bool MeuMetodoPuro();

	UFUNCTION(BlueprintCallable, Category = "NaoPuro")
	bool MeuMetodoNaoPuro();


};
