#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPHitResultType.h"
#include "HitResultConverterLibrary.generated.h"

/**
 * Helper lib to better use hit results in BP.
 */
UCLASS()
class UHitResultConverterLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Convert to BP accessible format */
	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast, CompactNodeTitle = "->", Keywords = "hit result FHitResult bp blueprint"))
	static FBPHitResult ConvertEngineHitResultToPluginHitResult(const FHitResult& InHitResult);
	
	/** Convert to in-engine format */
	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast, CompactNodeTitle = "->", Keywords = "hit result FHitResult bp blueprint"))
	static FHitResult ConvertPluginHitResultToEngineHitResult(const FBPHitResult& InHitResult);
};