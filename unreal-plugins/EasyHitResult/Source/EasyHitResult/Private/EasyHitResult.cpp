#include "EasyHitResult.h"

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IEasyHitResult.h"

class FEasyHitResult : public IEasyHitResult
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FEasyHitResult, EasyHitResult)

void FEasyHitResult::StartupModule()
{
}


void FEasyHitResult::ShutdownModule()
{
}