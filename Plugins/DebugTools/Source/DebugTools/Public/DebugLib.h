// Copyright 2020 Kevin Lichtenberg. All Rights Reserved.

#pragma once

#include "Core.h"
#include "UObject/NoExportTypes.h"
#include "DebugLib.generated.h"

UENUM(BlueprintType)
enum class EDebugLogChannel : uint8 {
    GENERAL 	UMETA(DisplayName = "General"),
    INVENTORY	UMETA(DisplayName = "Inventory"),
    AI      	UMETA(DisplayName = "AI"),
    SAVE_SYSTEM UMETA(DisplayName = "SaveSystem"),
    UI          UMETA(DisplayName = "UI"),
    VR          UMETA(DisplayName = "VR"),
    NETWORK     UMETA(DisplayName = "Network"),
};

UENUM(BlueprintType)
enum class EDebugLogType : uint8 {
    NORMAL 	    UMETA(DisplayName = "Normal"),
    WARNING	    UMETA(DisplayName = "Warning"),
    ERROR      	UMETA(DisplayName = "Error"),
};

// Credits to Rama, Source: https://www.ue4community.wiki/Logs,_Printing_Class_Name,_Function_Name,_Line_Number

//Current Class Name + Function Name where this is called!
#define CUR_CLASS_FUNC (FString(__FUNCTION__))

//Current Class where this is called!
#define CUR_CLASS (FString(__FUNCTION__).Left(FString(__FUNCTION__).Find(TEXT(":"))) )

//Current Function Name where this is called!
#define CUR_FUNC (FString(__FUNCTION__).Right(FString(__FUNCTION__).Len() - FString(__FUNCTION__).Find(TEXT("::")) - 2 ))

//Current Line Number in the code where this is called!
#define CUR_LINE  (FString::FromInt(__LINE__))

//Current Class and Line Number where this is called!
#define CUR_CLASS_LINE (CUR_CLASS + "::" + CUR_LINE)

//Current Function Signature where this is called!
#define CUR_FUNCSIG (FString(__FUNCSIG__))


// Log Macros
#define LOG(Message)                                UDebugLib::Log(Message + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL);
#define LOG_WARNING(Message)                        UDebugLib::LogWarning(Message + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL);
#define LOG_ERROR(Message)                          UDebugLib::LogError(Message + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL);

#define LOG_CHANNEL(Message, Channel)               UDebugLib::Log(Message + FString(" [") + CUR_CLASS_LINE + FString("]"), Channel);
#define LOG_CHANNEL_WARNING(Message, Channel)       UDebugLib::LogWarning(Message + FString(" [") + CUR_CLASS_LINE + FString("]"), Channel);
#define LOG_CHANNEL_ERROR(Message, Channel)         UDebugLib::LogError(Message + FString(" [") + CUR_CLASS_LINE + FString("]"), Channel);

#define LOG_BOOL(Message, Value)                    UDebugLib::Log(FString::Printf(TEXT("%s : %s"), TEXT(Message), Value ? TEXT("true") : TEXT("false")) + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL)
#define LOG_INT(Message, Value)                     UDebugLib::Log(FString::Printf(TEXT("%s : %d"), TEXT(Message), Value) + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL)
#define LOG_FLOAT(Message, Value)                   UDebugLib::Log(FString::Printf(TEXT("%s : %f"), TEXT(Message), Value) + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL)
#define LOG_STRING(Message, Value)                  UDebugLib::Log(FString::Printf(TEXT("%s : %s"), TEXT(Message), Value) + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL)
#define LOG_VECTOR(Message, Value)                  UDebugLib::Log(FString::Printf(TEXT("%s : %s"), TEXT(Message), *Value.ToString()) + FString(" [") + CUR_CLASS_LINE + FString("]"), EDebugLogChannel::GENERAL)


/**
 * A class that contains multiple static debug functions.
 */
UCLASS()
class DEBUGTOOLS_API UDebugLib : public UObject {
	GENERATED_BODY()

private:

    static void Log_Internal(const FString& Message, const EDebugLogChannel Channel);

    static void Log_InternalWarning(const FString& Message, const EDebugLogChannel Channel);

    static void Log_InternalError(const FString& Message, const EDebugLogChannel Channel);

    static void DrawDebugSweptSphere(UWorld* World, FVector const& Start, FVector const& End, float Radius, FColor const& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority = 0.0f);

    static void DrawDebugSweptBox(UWorld* World, FVector const& Start, FVector const& End, FVector HalfExtent, FRotator Orientation, FColor const& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority = 0.0f);

public:

    // ===================================
    // ======= BLUEPRINT FUNCTIONS =======
    // ===================================

    /**
    * Logs a default message in the given log.
    * Example: UDebugLib::Log(TEXT("My Message!"));
    * UDebugLib::Log(FString::Printf(TEXT("Some variable values: x: %f, y: %f"), 1.0f, 2.0f));
    */
    UFUNCTION(BlueprintCallable, Category = "Log")
    static void Log(const FString& Message, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);    

    /**
    * Logs a warning message in the given log.
    * Example: UDebugLib::Log(TEXT("My Message!"));
    * UDebugLib::LogWarning(FString::Printf(TEXT("Some variable values: x: %f, y: %f"), 1.0f, 2.0f));
    */
    UFUNCTION(BlueprintCallable, Category = "Log")
    static void LogWarning(const FString& Message, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);

    /**
    * Logs a error message in the given log.
    * Example: UDebugLib::Log(TEXT("My Message!"));
    * UDebugLib::LogError(FString::Printf(TEXT("Some variable values: x: %f, y: %f"), 1.0f, 2.0f));
    */
    UFUNCTION(BlueprintCallable, Category = "Log")
    static void LogError(const FString& Message, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);
    
    /**
	 * \brief Logs a message and a bool value in this format: "*Message*: *LogData*"
	 * \param Message
	 * \param LogData 
	 * \param LoggingType 
	 * \param LogChannel 
	 */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
	static void LogBool(const FString& Message, const bool LogData, const EDebugLogType LoggingType = EDebugLogType::NORMAL, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);

	/**
	* \brief Logs a message and a string value in this format: "*Message*: *LogData*"
	* \param Message
	* \param LogData 
	* \param LoggingType 
	* \param LogChannel 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void LogString(const FString& Message, const FString LogData, const EDebugLogType LoggingType = EDebugLogType::NORMAL, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);

	/**
	* \brief Logs a message and a int32 value in this format: "*Message*: *LogData*"
	* \param Message
	* \param LogData 
	* \param LoggingType 
	* \param LogChannel 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void LogInt(const FString& Message, const int32 LogData, const EDebugLogType LoggingType = EDebugLogType::NORMAL, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);

	/**
	* \brief Logs a message and a int64 value in this format: "*Message*: *LogData*"
	* \param Message
	* \param LogData 
	* \param LoggingType 
	* \param LogChannel 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void LogInt64(const FString& Message, const int64 LogData, const EDebugLogType LoggingType = EDebugLogType::NORMAL, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);

	/**
	* \brief Logs a message and a float value in this format: "*Message*: *LogData*"
	* \param Message
	* \param LogData 
	* \param LoggingType 
	* \param LogChannel 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void LogFloat(const FString& Message, const float LogData, const EDebugLogType LoggingType = EDebugLogType::NORMAL, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);

	/**
	* \brief Logs a message and a vector value in this format: "*Message*: *LogData*"
	* \param Message
	* \param LogData 
	* \param LoggingType 
	* \param LogChannel 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void LogVector(const FString& Message, const FVector& LogData, const EDebugLogType LoggingType = EDebugLogType::NORMAL, const EDebugLogChannel LogChannel = EDebugLogChannel::GENERAL);	

	// ====================================================================
	// =================== VISUAL / DISPLAY LOGS ==========================
	// ====================================================================

	
	/**
     * \brief Logs a given message to the log and displays it on the screen.
     * \param Message Your message
     * \param DisplayLength the time it will be displayed. Default 3 seconds. 
     */
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLog(const FString& Message, const float DisplayLength = 3.0f);

	/**
	* \brief Logs a given message to the log as a warning and displays it on the screen.
	* \param Message Your message
	* \param DisplayLength the time it will be displayed. Default 3 seconds. 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLogWaring(const FString& Message, const float DisplayLength = 3.0f);

	/**
	* \brief Logs a given message to the log as an error and displays it on the screen.
	* \param Message Your message
	* \param DisplayLength the time it will be displayed. Default 3 seconds. 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLogError(const FString& Message, const float DisplayLength = 3.0f);

	/**
     * \brief Display a message and a string value on the screen in this format: "*Message*: *LogData*"
     * \param Message 
     * \param LogData 
     * \param DisplayTime 
     * \param LoggingType 
     */
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLogString(const FString& Message, const FString& LogData, float DisplayTime = 3.0f, EDebugLogType LoggingType = EDebugLogType::NORMAL);

	/**
	* \brief Display a message and a int32 value on the screen in this format: "*Message*: *LogData*"
	* \param Message 
	* \param LogData 
	* \param DisplayTime 
	* \param LoggingType 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLogInt(const FString& Message, int32 LogData, float DisplayTime = 3.0f, EDebugLogType LoggingType = EDebugLogType::NORMAL);

	/**
	* \brief Display a message and a float value on the screen in this format: "*Message*: *LogData*"
	* \param Message 
	* \param LogData 
	* \param DisplayTime 
	* \param LoggingType 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLogFloat(const FString& Message, const float LogData, const float DisplayTime = 3.0f, EDebugLogType LoggingType = EDebugLogType::NORMAL);

	/**
	* \brief Display a message and a vector value on the screen in this format: "*Message*: *LogData*"
	* \param Message 
	* \param LogData 
	* \param DisplayTime 
	* \param LoggingType 
	*/
    UFUNCTION(BlueprintCallable, Category = "Blueprint Log")
    static void VLogVector(const FString& Message, const FVector& LogData, float DisplayTime = 3.0f, EDebugLogType LoggingType = EDebugLogType::NORMAL);
    
    // ======================================================== DRAW DEBUG FUNCTIONS ==========================================================================

	/**
     * \brief Visualizes a line trace
     * \param World The world to draw debug objects into
     * \param Start Start of the trace
     * \param End End of the trace
     * \param HitInfo The FHitResult from the trace
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever 
     */
    static void DrawDebugLineTrace(UWorld* World, const FVector& Start, const FVector& End, struct FHitResult& HitInfo, float LifeTime = 0);

	/**
     * \brief Visualizes a sphere trace
     * \param World The world to draw debug objects into
	 * \param Start Start of the trace
	 * \param End End of the trace
	 * \param HitInfo The FHitResult from the trace
     * \param Radius The sphere's radius
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
     */
    static void DrawDebugSphereTrace(UWorld* World, const FVector& Start, const FVector& End, struct FHitResult& HitInfo, float Radius, float LifeTime = 0);

	/**
	* \brief Visualizes a capsule trace
	* \param World The world to draw debug objects into
	* \param Start Start of the trace
	* \param End End of the trace
	* \param HitInfo The FHitResult from the trace
	* \param Radius The capsule's radius
	* \param HalfHeight The capsule's half height
	* \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
	*/
	static void DrawDebugCapsuleTrace(UWorld* World, const FVector& Start, const FVector& End, const FHitResult& HitInfo, float Radius, float HalfHeight,
	                                  float LifeTime);

	/**
     * \brief Draws a red point in the world
     * \param World The world to draw debug objects into
     * \param Location The location where to draw the point
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
     */
    static void DrawPoint(UWorld* World, const FVector& Location, float LifeTime);

	/**
     * \brief Draws a given string in the world
     * \param World The world to draw debug objects into
     * \param Location The location where to display the text
     * \param Text The actual text
     * \param Color The color of the text
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
     */
    static void DrawString(UWorld* World, const FVector& Location, const FString& Text, const FColor& Color, float LifeTime);

	/**
     * \brief Draws a sphere in the world
     * \param World The world to draw debug objects into
     * \param Location The location where to draw the sphere
     * \param Radius the sphere's radius
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
     */
    static void DrawSphere(UWorld* World, const FVector& Location, float Radius, float LifeTime);

	/**
     * \brief Draws a box in the world
     * \param World The world to draw debug objects into
     * \param Location The location where to draw the box
     * \param Orientation the orientation of the box
     * \param HalfExtent the HALF extent of the box
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
     */
    static void DrawBox(UWorld* World, const FVector& Location, const FRotator& Orientation, const FVector& HalfExtent, float LifeTime);

	/**
     * \brief Visualizes a box trace
     * \param World The world to draw debug objects into
     * \param Start The start of the box trace
     * \param End The end of the box trace
     * \param HitInfo The FHitResult of the trace
     * \param HalfExtent  the HALF extent of the box 
     * \param Orientation THe box's orientation 
     * \param LifeTime The time in seconds the line will we drawn in the world. LifeTime = 0: only for one frame. LifeTime = -1: forever
     */
    static void DrawDebugBoxTrace(UWorld* World, const FVector& Start, const FVector& End, struct FHitResult& HitInfo, const FVector& HalfExtent, const FRotator& Orientation, float LifeTime = 0);
    
};
