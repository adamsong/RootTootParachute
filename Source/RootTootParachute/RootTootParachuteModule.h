#pragma once

#include "Modules/ModuleManager.h"
#include "Sound/SoundCue.h"

class FRootTootParachuteModule : public FDefaultGameModuleImpl {
public:

	virtual void StartupModule() override;

	virtual bool IsGameModule() const override { return true; }
    
private:
    void SetupHooks();
};

DECLARE_LOG_CATEGORY_EXTERN(LogRootTootParachute, Log, Log);