// Copyright 2020 Kevin Lichtenberg. All Rights Reserved.


#include "DebugLib.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "DebugTools.h"

static const FLinearColor TraceColor = FLinearColor::Red;
static const FLinearColor TraceHitColor = FLinearColor::Green;
static const float TraceImpactPointSize = 16.0f;

void UDebugLib::Log_Internal(const FString& Message, const EDebugLogChannel Channel) {
    switch (Channel) {
    case EDebugLogChannel::GENERAL:
        UE_LOG(LogGeneral, Display, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::INVENTORY:
        UE_LOG(LogInventory, Display, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::AI:
        UE_LOG(LogAI, Display, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::SAVE_SYSTEM:
        UE_LOG(LogSaveSystem, Display, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::UI:
        UE_LOG(LogUI, Display, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::VR:
        UE_LOG(LogVR, Display, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::NETWORK:
        UE_LOG(LogNetwork, Display, TEXT("%s"), *Message);
        break;
    default:
        UE_LOG(LogGeneral,Display, TEXT("%s"), *Message);
        break;
    }
}

void UDebugLib::Log_InternalWarning(const FString& Message, const EDebugLogChannel Channel) {
    switch (Channel) {
    case EDebugLogChannel::GENERAL:
        UE_LOG(LogGeneral, Warning, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::INVENTORY:
        UE_LOG(LogInventory, Warning, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::AI:
        UE_LOG(LogAI, Warning, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::SAVE_SYSTEM:
        UE_LOG(LogSaveSystem, Warning, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::UI:
        UE_LOG(LogUI, Warning, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::VR:
        UE_LOG(LogVR, Warning, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::NETWORK:
        UE_LOG(LogNetwork, Warning, TEXT("%s"), *Message);
        break;
    default:
        UE_LOG(LogGeneral, Warning, TEXT("%s"), *Message);
        break;
    }
}

void UDebugLib::Log_InternalError(const FString& Message, const EDebugLogChannel Channel) {
    switch (Channel) {
    case EDebugLogChannel::GENERAL:
        UE_LOG(LogGeneral, Error, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::INVENTORY:
        UE_LOG(LogInventory, Error, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::AI:
        UE_LOG(LogAI, Error, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::SAVE_SYSTEM:
        UE_LOG(LogSaveSystem, Error, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::UI:
        UE_LOG(LogUI, Error, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::VR:
        UE_LOG(LogVR, Error, TEXT("%s"), *Message);
        break;
    case EDebugLogChannel::NETWORK:
        UE_LOG(LogNetwork, Error, TEXT("%s"), *Message);
        break;
    default:
        UE_LOG(LogGeneral, Error, TEXT("%s"), *Message);
        break;
    }
}



void UDebugLib::Log(const FString& Message, const EDebugLogChannel LogChannel) {
    Log_Internal(Message, LogChannel);
}

void UDebugLib::LogWarning(const FString& Message, const EDebugLogChannel LogChannel) {
    Log_InternalWarning(Message, LogChannel);
}

void UDebugLib::LogError(const FString& Message, const EDebugLogChannel LogChannel) {
    Log_InternalError(Message, LogChannel);
}

void UDebugLib::LogBool(const FString& Message, const bool LogData, const EDebugLogType LoggingType,
                           const EDebugLogChannel LogChannel) {

    FString BoolSting = FString::Printf(TEXT("FALSE"));
    if (LogData) {
        BoolSting = FString::Printf(TEXT("TRUE"));
    }

    const FString Temp = FString::Printf(TEXT("%s: %s"), *Message, *BoolSting);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        Log(Temp, LogChannel);
        break;
    case EDebugLogType::WARNING:
        LogWarning(Temp, LogChannel);
        break;
    case EDebugLogType::ERROR:
        LogError(Temp, LogChannel);
        break;
    default:
        break;
    }

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Temp);
    }
}

void UDebugLib::LogString(const FString& Message, const FString LogData, const EDebugLogType LoggingType,
                             const EDebugLogChannel LogChannel) {

    const FString Temp = FString::Printf(TEXT("%s: %s"), *Message, *LogData);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        Log(Temp, LogChannel);
        break;
    case EDebugLogType::WARNING:
        LogWarning(Temp, LogChannel);
        break;
    case EDebugLogType::ERROR:
        LogError(Temp, LogChannel);
        break;
    default:
        break;
    }

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Temp);
    }
}

void UDebugLib::LogInt(const FString& Message, const int32 LogData, const EDebugLogType LoggingType,
                       const EDebugLogChannel LogChannel) {

    const FString Temp = FString::Printf(TEXT("%s: %d"), *Message, LogData);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        Log(Temp, LogChannel);
        break;
    case EDebugLogType::WARNING:
        LogWarning(Temp, LogChannel);
        break;
    case EDebugLogType::ERROR:
        LogError(Temp, LogChannel);
        break;
    default:
        break;
    }

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Temp);
    }
}

void UDebugLib::LogInt64(const FString& Message, const int64 LogData, const EDebugLogType LoggingType,
                            const EDebugLogChannel LogChannel) {

    const FString Temp = FString::Printf(TEXT("%s: %lld"), *Message, LogData);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        Log(Temp, LogChannel);
        break;
    case EDebugLogType::WARNING:
        LogWarning(Temp, LogChannel);
        break;
    case EDebugLogType::ERROR:
        LogError(Temp, LogChannel);
        break;
    default:
        break;
    }

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Temp);
    }
}

void UDebugLib::LogFloat(const FString& Message, const float LogData, const EDebugLogType LoggingType,
                            const EDebugLogChannel LogChannel) {

    const FString Temp = FString::Printf(TEXT("%s: %f"), *Message, LogData);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        Log(Temp, LogChannel);
        break;
    case EDebugLogType::WARNING:
        LogWarning(Temp, LogChannel);
        break;
    case EDebugLogType::ERROR:
        LogError(Temp, LogChannel);
        break;
    default:
        break;
    }

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Temp);
    }
}

void UDebugLib::LogVector(const FString& Message, const FVector& LogData, EDebugLogType LoggingType,
                             EDebugLogChannel LogChannel) {

    const FString Temp = FString::Printf(TEXT("%s: %s"), *Message, *LogData.ToString());

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        Log(Temp, LogChannel);
        break;
    case EDebugLogType::WARNING:
        LogWarning(Temp, LogChannel);
        break;
    case EDebugLogType::ERROR:
        LogError(Temp, LogChannel);
        break;
    default:
        break;
    }

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Temp);
    }
}

void UDebugLib::VLog(const FString& Message, float DisplayLength) {
    Log(Message, EDebugLogChannel::GENERAL);
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, DisplayLength, FColor::White, Message);
    }
}

void UDebugLib::VLogWaring(const FString& Message, float DisplayLength) {
    LogWarning(Message, EDebugLogChannel::VR);
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, DisplayLength, FColor::Yellow, Message);
    }
}

void UDebugLib::VLogError(const FString& Message, const float DisplayLength) {
    LogError(Message, EDebugLogChannel::VR);
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, DisplayLength, FColor::Red, Message);
    }
}

void UDebugLib::VLogString(const FString& Message, const FString& LogData, float DisplayTime,
                               EDebugLogType LoggingType) {

    const FString Temp = FString::Printf(TEXT("%s: %s"), *Message, *LogData);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        VLog(Temp, DisplayTime);
        break;
    case EDebugLogType::WARNING:
        VLogWaring(Temp, DisplayTime);
        break;
    case EDebugLogType::ERROR:
        VLogError(Temp, DisplayTime);
        break;
    default:
        break;
    }
}

void UDebugLib::VLogInt(const FString& Message, const int32 LogData, float DisplayTime, EDebugLogType LoggingType) {
    const FString Temp = FString::Printf(TEXT("%s: %d"), *Message, LogData);

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        VLog(Temp, DisplayTime);
        break;
    case EDebugLogType::WARNING:
        VLogWaring(Temp, DisplayTime);
        break;
    case EDebugLogType::ERROR:
        VLogError(Temp, DisplayTime);
        break;
    default:
        break;
    }
}

void UDebugLib::VLogFloat(const FString& Message, const float LogData, float DisplayTime,
                              EDebugLogType LoggingType) {

    const FString Temp = FString::Printf(TEXT("%s: %f"), *Message, LogData);
    
    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        VLog(Temp, DisplayTime);
        break;
    case EDebugLogType::WARNING:
        VLogWaring(Temp, DisplayTime);
        break;
    case EDebugLogType::ERROR:
        VLogError(Temp, DisplayTime);
        break;
    default:
        break;
    }
    
}

void UDebugLib::VLogVector(const FString& Message, const FVector& LogData, float DisplayTime,
                               EDebugLogType LoggingType) {

    const FString Temp = FString::Printf(TEXT("%s: %s"), *Message, *LogData.ToString());

    switch (LoggingType) {
    case EDebugLogType::NORMAL:
        VLog(Temp, DisplayTime);
        break;
    case EDebugLogType::WARNING:
        VLogWaring(Temp, DisplayTime);
        break;
    case EDebugLogType::ERROR:
        VLogError(Temp, DisplayTime);
        break;
    default:
        break;
    }
    
}

void UDebugLib::DrawDebugSweptSphere(UWorld* World, FVector const& Start, FVector const& End, const float Radius,
    FColor const& Color, const bool bPersistentLines, const float LifeTime, const uint8 DepthPriority) {
    
    FVector const TraceVec = End - Start;
    float const Dist = TraceVec.Size();

    FVector const Center = Start + TraceVec * 0.5f;
    float const HalfHeight = (Dist * 0.5f) + Radius;
    
    FQuat const CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
    DrawDebugCapsule(World, Center, HalfHeight, Radius, CapsuleRot, Color, bPersistentLines, LifeTime, DepthPriority);
}

void UDebugLib::DrawDebugSweptBox(UWorld* World, FVector const& Start, FVector const& End, const FVector HalfExtent,
                                  const FRotator Orientation, FColor const& Color, const bool bPersistentLines, const float LifeTime, const uint8 DepthPriority) {

    FVector const TraceVec = End - Start;
    float const Dist = TraceVec.Size();

    FVector const Center = Start + TraceVec * 0.5f;

    FQuat const CapsuleRot = Orientation.Quaternion();
    DrawDebugBox(World, Start, HalfExtent, CapsuleRot, Color, bPersistentLines, LifeTime, DepthPriority);

    //now draw lines from vertices
    FVector Vertices[8];
    Vertices[0] = Start + Orientation.RotateVector(FVector(-HalfExtent.X, -HalfExtent.Y, -HalfExtent.Z));	//flt
    Vertices[1] = Start + Orientation.RotateVector(FVector(-HalfExtent.X, HalfExtent.Y, -HalfExtent.Z));	//frt
    Vertices[2] = Start + Orientation.RotateVector(FVector(-HalfExtent.X, -HalfExtent.Y, HalfExtent.Z));	//flb
    Vertices[3] = Start + Orientation.RotateVector(FVector(-HalfExtent.X, HalfExtent.Y, HalfExtent.Z));	//frb
    Vertices[4] = Start + Orientation.RotateVector(FVector(HalfExtent.X, -HalfExtent.Y, -HalfExtent.Z));	//blt
    Vertices[5] = Start + Orientation.RotateVector(FVector(HalfExtent.X, HalfExtent.Y, -HalfExtent.Z));	//brt
    Vertices[6] = Start + Orientation.RotateVector(FVector(HalfExtent.X, -HalfExtent.Y, HalfExtent.Z));	//blb
    Vertices[7] = Start + Orientation.RotateVector(FVector(HalfExtent.X, HalfExtent.Y, HalfExtent.Z));		//brb
    for (int32 VertexIdx = 0; VertexIdx < 8; ++VertexIdx) {
        DrawDebugLine(World, Vertices[VertexIdx], Vertices[VertexIdx] + TraceVec, Color, bPersistentLines, LifeTime, DepthPriority);
    }

    DrawDebugBox(World, End, HalfExtent, CapsuleRot, Color, bPersistentLines, LifeTime, DepthPriority);    
}

void UDebugLib::DrawDebugLineTrace(UWorld* World, const FVector& Start, const FVector& End, FHitResult& HitInfo, float LifeTime) {

    const bool bPersistent = false;

    if (HitInfo.bBlockingHit) {
        DrawDebugLine(World, Start, HitInfo.ImpactPoint, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugPoint(World, HitInfo.ImpactPoint, 16.0f, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugLine(World, HitInfo.ImpactPoint, End, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
    } else {
        DrawDebugLine(World, Start, End, TraceColor.ToFColor(true), bPersistent, LifeTime);
    }
    
}

void UDebugLib::DrawDebugSphereTrace(UWorld* World, const FVector& Start, const FVector& End, FHitResult& HitInfo, float Radius,
                                        float LifeTime) {

    const bool bPersistent = false;

    if (HitInfo.bBlockingHit) {
        // Red up to the blocking hit, green thereafter
        DrawDebugSweptSphere(World, Start, HitInfo.Location, Radius, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugSweptSphere(World, HitInfo.Location, End, Radius, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugPoint(World, HitInfo.ImpactPoint, TraceImpactPointSize, TraceColor.ToFColor(true), bPersistent, LifeTime);
    } else {
        // no hit means all red
        DrawDebugSweptSphere(World, Start, End, Radius, TraceColor.ToFColor(true), bPersistent, LifeTime);
    }
    
}

void UDebugLib::DrawDebugCapsuleTrace(UWorld* World, const FVector& Start, const FVector& End, const FHitResult& HitInfo, float Radius, float HalfHeight, float LifeTime) {    

    const bool bPersistent = false;

    if (HitInfo.bBlockingHit) {
        // Red up to the blocking hit, green thereafter
        DrawDebugCapsule(World, Start, HalfHeight, Radius, FQuat::Identity, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugCapsule(World, HitInfo.Location, HalfHeight, Radius, FQuat::Identity, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugLine(World, Start, HitInfo.Location, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugPoint(World, HitInfo.ImpactPoint, TraceImpactPointSize, TraceColor.ToFColor(true), bPersistent, LifeTime);

        DrawDebugCapsule(World, End, HalfHeight, Radius, FQuat::Identity, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugLine(World, HitInfo.Location, End, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
    } else {
        // no hit means all red
        DrawDebugCapsule(World, Start, HalfHeight, Radius, FQuat::Identity, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugCapsule(World, End, HalfHeight, Radius, FQuat::Identity, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugLine(World, Start, End, TraceColor.ToFColor(true), bPersistent, LifeTime);
    }
}

void UDebugLib::DrawPoint(UWorld* World, const FVector& Location, const float LifeTime) {
    DrawDebugPoint(World, Location, 16.0f, FColor::Red, true, LifeTime);
}

void UDebugLib::DrawString(UWorld* World, const FVector& Location, const FString& Text, const FColor& Color, const float LifeTime) {
    DrawDebugString(World, Location, Text, nullptr, Color, LifeTime);
}

void UDebugLib::DrawSphere(UWorld* World, const FVector& Location, const float Radius, const float LifeTime) {
    const bool bPersistent = true;
    DrawDebugSphere(World, Location, Radius, 16.0f, FColor::Red, bPersistent, LifeTime);
}

void UDebugLib::DrawBox(UWorld* World, const FVector& Location, const FRotator& Orientation, const FVector& HalfExtent, const float LifeTime) {
    const bool bPersistent = true;
    DrawDebugBox(World, Location, HalfExtent, FColor::Red, bPersistent, LifeTime);
}

void UDebugLib::DrawDebugBoxTrace(UWorld* World, const FVector& Start, const FVector& End, FHitResult& HitInfo, const FVector& HalfExtent,
                                     const FRotator& Orientation, const float LifeTime) {
    const bool bPersistent = false;

    if (HitInfo.bBlockingHit) {
        // Red up to the blocking hit, green thereafter
        DrawDebugSweptBox(World, Start, HitInfo.Location, HalfExtent, Orientation, TraceColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugSweptBox(World, HitInfo.Location, End, HalfExtent, Orientation, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
        DrawDebugPoint(World, HitInfo.ImpactPoint, TraceImpactPointSize, TraceColor.ToFColor(true), bPersistent, LifeTime);
    } else {
        // no hit means all red
        DrawDebugSweptBox(World, Start, End, HalfExtent, Orientation, TraceColor.ToFColor(true), bPersistent, LifeTime);
    }
}
