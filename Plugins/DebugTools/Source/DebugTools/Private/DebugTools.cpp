// Copyright 2020 Kevin Lichtenberg. All Rights Reserved.

#include "DebugTools.h"

// === LOGS ===

DEFINE_LOG_CATEGORY(LogGeneral);

DEFINE_LOG_CATEGORY(LogAI);

DEFINE_LOG_CATEGORY(LogInventory);

DEFINE_LOG_CATEGORY(LogSaveSystem);

DEFINE_LOG_CATEGORY(LogUI);

DEFINE_LOG_CATEGORY(LogVR);

DEFINE_LOG_CATEGORY(LogNetwork);


#define LOCTEXT_NAMESPACE "FDebugToolsModule"

void FDebugToolsModule::StartupModule() {
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FDebugToolsModule::ShutdownModule() {
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDebugToolsModule, DebugTools)
