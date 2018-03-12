#include "BPHitResultType.h"
#include "Kismet/GameplayStatics.h"


FBPHitResult::FBPHitResult(const FHitResult& InResult) :
bBlockingHit(InResult.bBlockingHit),
bStartPenetrating(InResult.bStartPenetrating),
Time(InResult.Time),
Distance(InResult.Distance),
Location(InResult.Location),
ImpactPoint(InResult.ImpactPoint),
Normal(InResult.Normal),
ImpactNormal(InResult.ImpactNormal),
TraceStart(InResult.TraceStart),
TraceEnd(InResult.TraceEnd),
PenetrationDepth(InResult.PenetrationDepth),
Item(InResult.Item),
PhysMaterial(InResult.PhysMaterial),
Actor(InResult.Actor),
Component(InResult.Component),
BoneName(InResult.BoneName),
FaceIndex(InResult.FaceIndex)
{}

FHitResult FBPHitResult::ToHitResult() const
{
	return UGameplayStatics::MakeHitResult(bBlockingHit, bStartPenetrating, Time, Distance, Location, ImpactPoint, Normal, ImpactNormal, PhysMaterial.Get(), Actor.Get(), Component.Get(), BoneName, Item, FaceIndex, TraceStart, TraceEnd);
}
