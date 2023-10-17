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

TArray<FVector> ASplineGenerator::GenerateCircularSplineVector3D(const int32 NumOfPoints, const float Radius, const FRandomStream Seed, const int32 PointDeviation)
{
	TArray<FVector> SplinePoints;

	if (NumOfPoints < 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("Number of points must be at least 2."));
		return SplinePoints;
	}

	const float AngleIncrement = 360.0f / static_cast<float>(NumOfPoints - 1);
	for (int32 PointIndex = 0; PointIndex < NumOfPoints - 1; ++PointIndex)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("SEED RAND: %f"), Seed.FRand()));
		const float AngleInRad = FMath::DegreesToRadians(AngleIncrement * PointIndex);
		const float X = FMath::Cos(AngleInRad) * (Radius + Seed.RandRange(0, PointDeviation));
		const float Y = FMath::Sin(AngleInRad) * (Radius + Seed.RandRange(0, PointDeviation));

		SplinePoints.Add(FVector(X, Y, 0.0f));
	}

	return SplinePoints;
}
