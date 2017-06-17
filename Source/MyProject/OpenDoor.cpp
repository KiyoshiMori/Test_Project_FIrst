// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	AActor* Door = GetOwner();
	FVector owner_pos = Door->GetActorLocation();
	MyDoor->SetWorldLocation(owner_pos);
	MyDoor->AddLocalOffset(FVector(0.f, 45.f, 0.f));


	// ...
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PresurePlate->IsOverlappingActor(Player)) {
		OpenDoor();
	}
}

void UOpenDoor::OpenDoor()
{

	FRotator NewRotator = FRotator(0.f, 90.f, 0.f);
	//Door->GetRootComponent()->GetChildComponent(1)->SetVisibility(false);
	MyDoor->SetWorldRotation(NewRotator);
}

