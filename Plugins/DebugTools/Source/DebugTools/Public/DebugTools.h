// Copyright 2020 Kevin Lichtenberg. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

// IMPORTANT: Also add new logs in FwESI.cpp!!

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogGeneral, Log, All);

// Logging for save system
DECLARE_LOG_CATEGORY_EXTERN(LogSaveSystem, Log, All);

// Logging for inventory system
DECLARE_LOG_CATEGORY_EXTERN(LogInventory, Log, All);

// // Logging for your AI system
DECLARE_LOG_CATEGORY_EXTERN(LogAI, Log, All);

// Logging for your UI system
DECLARE_LOG_CATEGORY_EXTERN(LogUI, Log, All);

DECLARE_LOG_CATEGORY_EXTERN(LogVR, Log, All);

// Logging for your NETWORK system
DECLARE_LOG_CATEGORY_EXTERN(LogNetwork, Log, All);

class FDebugToolsModule : public IModuleInterface {
public:

    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
