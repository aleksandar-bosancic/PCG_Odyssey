// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineGenerator.h"

#include "Components/SplineComponent.h"

// Sets default values
ASplineGenerator::ASplineGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASplineGenerator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASplineGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<FVector> ASplineGenerator::GenerateCircularSplineVector3D(int32 NumOfPoints, float Radius)
{
	TArray<FVector> SplinePoints;

	if (NumOfPoints < 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("Number of points must be at least 2."));
		return SplinePoints;
	}

	const float AngleIncrement = 360.0f / static_cast<float>(NumOfPoints - 1);
	for (int32 PointIndex = 0; PointIndex < NumOfPoints; ++PointIndex)
	{
		const float AngleInRad = FMath::DegreesToRadians(AngleIncrement * PointIndex);
		const float X = FMath::Cos(AngleInRad) * (Radius + (rand() % 1000));
		const float Y = FMath::Sin(AngleInRad) * (Radius + (rand() % 1000));

		SplinePoints.Add(FVector(X, Y, 0.0f));
	}

	return SplinePoints;
}
