#pragma once

#include "Engine/EngineTypes.h"
#include "BPHitResultType.generated.h"

struct FHitResult;

/**
 * Blueprint mirror for FHitResult.
 */
USTRUCT(BlueprintType)
struct FBPHitResult 
{
	GENERATED_USTRUCT_BODY()

	FBPHitResult() {}

	FBPHitResult(const FHitResult& InResult);
	FHitResult ToHitResult() const;

	/** Indicates if this hit was a result of blocking collision. If false, there was no hit or it was an overlap/touch instead. */
	UPROPERTY(BlueprintReadWrite)
	uint32 bBlockingHit:1;

	/**
	 * Whether the trace started in penetration, i.e. with an initial blocking overlap.
	 * In the case of penetration, if PenetrationDepth > 0.f, then it will represent the distance along the Normal vector that will result in
	 * minimal contact between the swept shape and the object that was hit. In this case, ImpactNormal will be the normal opposed to movement at that location
	 * (ie, Normal may not equal ImpactNormal). ImpactPoint will be the same as Location, since there is no single impact point to report.
	 */
	UPROPERTY(BlueprintReadWrite)
	uint32 bStartPenetrating:1;

	/**
	 * 'Time' of impact along trace direction (ranging from 0.0 to 1.0) if there is a hit, indicating time between TraceStart and TraceEnd.
	 * For swept movement (but not queries) this may be pulled back slightly from the actual time of impact, to prevent precision problems with adjacent geometry.
	 */
	UPROPERTY(BlueprintReadWrite)
	float Time;
	 
	/** The distance from the TraceStart to the Location in world space. This value is 0 if there was an initial overlap (trace started inside another colliding object). */
	UPROPERTY(BlueprintReadWrite)
	float Distance; 
	
	/**
	 * The location in world space where the moving shape would end up against the impacted object, if there is a hit. Equal to the point of impact for line tests.
	 * Example: for a sphere trace test, this is the point where the center of the sphere would be located when it touched the other object.
	 * For swept movement (but not queries) this may not equal the final location of the shape since hits are pulled back slightly to prevent precision issues from overlapping another surface.
	 */
	UPROPERTY(BlueprintReadWrite)
	FVector Location;

	/**
	 * Location in world space of the actual contact of the trace shape (box, sphere, ray, etc) with the impacted object.
	 * Example: for a sphere trace test, this is the point where the surface of the sphere touches the other object.
	 * @note: In the case of initial overlap (bStartPenetrating=true), ImpactPoint will be the same as Location because there is no meaningful single impact point to report.
	 */
	UPROPERTY(BlueprintReadWrite)
	FVector ImpactPoint;

	/**
	 * Normal of the hit in world space, for the object that was swept. Equal to ImpactNormal for line tests.
	 * This is computed for capsules and spheres, otherwise it will be the same as ImpactNormal.
	 * Example: for a sphere trace test, this is a normalized vector pointing in towards the center of the sphere at the point of impact.
	 */
	UPROPERTY(BlueprintReadWrite)
	FVector Normal;

	/**
	 * Normal of the hit in world space, for the object that was hit by the sweep, if any.
	 * For example if a box hits a flat plane, this is a normalized vector pointing out from the plane.
	 * In the case of impact with a corner or edge of a surface, usually the "most opposing" normal (opposed to the query direction) is chosen.
	 */
	UPROPERTY(BlueprintReadWrite)
	FVector ImpactNormal;

	/**
	 * Start location of the trace.
	 * For example if a sphere is swept against the world, this is the starting location of the center of the sphere.
	 */
	UPROPERTY(BlueprintReadWrite)
	FVector TraceStart;

	/**
	 * End location of the trace; this is NOT where the impact occurred (if any), but the furthest point in the attempted sweep.
	 * For example if a sphere is swept against the world, this would be the center of the sphere if there was no blocking hit.
	 */
	UPROPERTY(BlueprintReadWrite)
	FVector TraceEnd;

	/**
	  * If this test started in penetration (bStartPenetrating is true) and a depenetration vector can be computed,
	  * this value is the distance along Normal that will result in moving out of penetration.
	  * If the distance cannot be computed, this distance will be zero.
	  */
	UPROPERTY(BlueprintReadWrite)
	float PenetrationDepth;

	/** Extra data about item that was hit (hit primitive specific). */
	UPROPERTY(BlueprintReadWrite)
	int32 Item;

	/**
	 * Physical material that was hit.
	 * @note Must set bReturnPhysicalMaterial on the swept PrimitiveComponent or in the query params for this to be returned.
	 */
	UPROPERTY(BlueprintReadWrite)
	TWeakObjectPtr<class UPhysicalMaterial> PhysMaterial;

	/** Actor hit by the trace. */
	UPROPERTY(BlueprintReadWrite)
	TWeakObjectPtr<class AActor> Actor;

	/** PrimitiveComponent hit by the trace. */
	UPROPERTY(BlueprintReadWrite)
	TWeakObjectPtr<class UPrimitiveComponent> Component;

	/** Name of bone we hit (for skeletal meshes). */
	UPROPERTY(BlueprintReadWrite)
	FName BoneName;

	/** Face index we hit (for complex hits with triangle meshes). */
	UPROPERTY(BlueprintReadWrite)
	int32 FaceIndex;
};