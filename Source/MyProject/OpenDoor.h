// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
	AActor* ActorReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FComponentReference opdo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* MyDoor;
private:
	UPROPERTY(EditAnywhere)
	AVolume* PresurePlate;
	UPROPERTY(EditAnywhere)
	AActor* Player;
	
};
