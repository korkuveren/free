#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class IEasyHitResult : public IModuleInterface
{
public:

	static inline IEasyHitResult& Get()
	{
		return FModuleManager::LoadModuleChecked<IEasyHitResult>("EasyHitResult");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("EasyHitResult");
	}
};