#include "HitResultConverterLibrary.h"

FBPHitResult UHitResultConverterLibrary::ConvertEngineHitResultToPluginHitResult(const FHitResult& InHitResult)
{
	return FBPHitResult(InHitResult);
}

FHitResult UHitResultConverterLibrary::ConvertPluginHitResultToEngineHitResult(const FBPHitResult& InHitResult)
{
	return InHitResult.ToHitResult();
}