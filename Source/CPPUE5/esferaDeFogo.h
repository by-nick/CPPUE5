// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "esferaDeFogo.generated.h"

UCLASS()
class CPPUE5_API AesferaDeFogo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AesferaDeFogo();

private:
	
	/*
	 1 - Possibilita que o editor UE possa ver.
	 2 - Pode editar essa var no editor da UE.
	 3 - E fala em qual categoria a var aparece no editor
	*/
	UPROPERTY(EditAnywhere, Category = "Componentes")
	//ponteiro para um modelo 3D (mesh) visivel (o que o player ve realmente no jogo)
	UStaticMeshComponent* EsferaVisivel;

	UPROPERTY(EditAnywhere, Category = "Componentes")
	//quer dizer que existe uma classe chamada EsferaDeColisao
	 class USphereComponent* EsferaDeColisao;

	 UPROPERTY(EditAnywhere, Category = "Componentes")
	 UParticleSystemComponent* ParticulaDeFogo;

protected:

	//Faz com que essas variaveis criadas apareçam no editor da UE

	UPROPERTY(EditAnywhere, Category = "Variaveis")
	bool VariavelEditAniwhere;

	UPROPERTY(EditAnywhere, Category = "Variaveis")
	float VariavelVisivel;

	UPROPERTY(EditDefaultsOnly, Category = "Variaveis")
	float VariavelEditDefaultOnly;

	UPROPERTY(VisibleDefaultsOnly, Category = "Variaveis")
	float VariavelVisibleDefaultOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")
	FVector VariavelBlueprintReadWrite = FVector(0.f, 0.f, -180.f);

	UPROPERTY(BlueprintReadOnly, Category = "Variaveis")
	FString VariavelBlueprintReadOnly = "Texto Blueprint";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")
	FString VariavelEditAnywhereBlueprintReadWrite = "Texto Editavel";
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variaveis")
	FString VariavelEditAnywhereBlueprintOnly = "Outro Texto";


	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Sobreposicoes")
	void ImplementeParaMim();
	
	//macro ufunction
	UFUNCTION(BlueprintNativeEvent)
	void IniciouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);

	void IniciouSobreposicao_Implementation(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent)
	void TerminouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);

	void TerminouSobreposicao_Implementation(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Texto")

	//forward declaration
	class UTextRenderComponent* TextoDeExibicao;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
