#include "RootTootParachuteModule.h"

#include "Components/AudioComponent.h"
#include "Equipment/FGParachute.h"
#include "Kismet/GameplayStatics.h"
#include "Patching/NativeHookManager.h"
#include "UObject/ConstructorHelpers.h"

void FRootTootParachuteModule::StartupModule() {
    SetupHooks();
}

void FRootTootParachuteModule::SetupHooks() {
#if !WITH_EDITOR
    TSoftObjectPtr<USoundCue> YeeHawSound = TSoftObjectPtr<USoundCue>(FSoftObjectPath(TEXT("SoundCue'/RootTootParachute/Audio/YeeHawCue.YeeHawCue'")));
    SUBSCRIBE_METHOD(AFGParachute::OnDeployed, [YeeHawSound](auto& scope, const AFGParachute* self) {

        USoundCue* yeeHaw = YeeHawSound.LoadSynchronous();
        FVector location = self->GetActorLocation();

        UGameplayStatics::PlaySoundAtLocation(self, yeeHaw, self->GetActorLocation());

    });
#endif // !WITH_EDITOR
}

IMPLEMENT_GAME_MODULE(FRootTootParachuteModule, RootTootParachute);

DEFINE_LOG_CATEGORY(LogRootTootParachute);