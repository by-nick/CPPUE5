// Fill out your copyright notice in the Description page of Project Settings.


#include "esferaDeFogo.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AesferaDeFogo::AesferaDeFogo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;

	//Cria um componente de esfera no actor 
	EsferaDeColisao = CreateDefaultSubobject<USphereComponent>(TEXT("Raiz"));

	//Define o tamanho do raio da esfera
	EsferaDeColisao->InitSphereRadius(100.f);

	//define no tipo de colisão
	EsferaDeColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	//raiz do objeto
	/*
	* Root = Componente principal 
	* Ponto de referencia da posição
	* Tudo que for anexado ao actor seguirá a posição dessa esfera
	*/
	RootComponent = EsferaDeColisao;


	//Visibilidade da esfera (Mesh)
	EsferaVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Esfera"));
	ParticulaDeFogo = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particula Fogo"));

	ParticulaDeFogo->SetupAttachment(EsferaVisivel);
	ParticulaDeFogo->bAutoActivate = true;

	//cria componente de texto de exibição
	TextoDeExibicao = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Texto"));


	//Anexa o componente de texto como filho de esfera visivel 
	TextoDeExibicao->SetupAttachment(EsferaVisivel);

	//Localização do texto com relação ao componente pai, 110.f no eixo Z
	TextoDeExibicao->SetRelativeLocation(FVector(0.f, 0.f, 180.f));

	//Alinha o texto de forma centralizada
	TextoDeExibicao->SetHorizontalAlignment(EHTA_Center);

	//Influencia o tamanho da escala do texto em x e y
	TextoDeExibicao->SetYScale(2.f);
	TextoDeExibicao->SetXScale(2.f);
	TextoDeExibicao->SetXScale(2.f);

	//converte o texto para string e adiciona o texto padrão
	TextoDeExibicao->SetText(FText::FromString("Olá Nick!!"));

	//cor do texto
	TextoDeExibicao->SetTextRenderColor(FColor::Red);

	//torna o texto visivel
	TextoDeExibicao->SetVisibility(true);


	//quando algo passar por mim, execute esta função. se chama DELEGATE
	OnActorBeginOverlap.AddDynamic(this, &AesferaDeFogo::IniciouSobreposicao);

	//se algo parar de encostar execute esta função
	OnActorEndOverlap.AddDynamic(this, &AesferaDeFogo::TerminouSobreposicao);


	/*
	Ferramenta para busca de mesh na UE
	Esfera -> Var que vai guardar o que a UE achou no buscador
	TEXT -> Macro de conversão da UE de texto para Unicode
	*/
	ConstructorHelpers::FObjectFinder<UStaticMesh>Esfera(TEXT("/Engine/Tutorial/SubEditors/TutorialAssets"));
	ConstructorHelpers::FObjectFinder<UParticleSystem>Fogo(TEXT("/Engine/Tutorial/SubEditors/TutorialAssets"));


	//se a esfera for encontrada...
	if (Esfera.Succeeded() && Fogo.Succeeded()) {
		EsferaVisivel->SetStaticMesh(Esfera.Object);
		ParticulaDeFogo->SetTemplate(Fogo.Object);
		EsferaVisivel->SetRelativeLocation(FVector(0.f, 0.f, -60.f));

	}

	//linka a esfera visivel na raiz
	EsferaVisivel->SetupAttachment(RootComponent);

	/*
	Se a raiz mover = mesh se move
	se raiz rotacionar = mesh rotaciona 
	*/


}

// Called when the game starts or when spawned
void AesferaDeFogo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AesferaDeFogo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AesferaDeFogo::IniciouSobreposicao_Implementation(AActor* OverlappedActor, AActor* OtherActor) {

	FString StringDeSaida;
	StringDeSaida = "Sobrepondo via Código C++ o ator: " + OtherActor->GetName() + " !";

		TextoDeExibicao->SetText(FText::FromString(StringDeSaida));

}
void AesferaDeFogo::TerminouSobreposicao_Implementation(AActor* OverlappedActor, AActor* OtherActor) {
	TextoDeExibicao->SetText(FText::FromString(TEXT("Saiu da Sobreposição via Código C++")));
}
