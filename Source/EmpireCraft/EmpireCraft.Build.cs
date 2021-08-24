// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EmpireCraft : ModuleRules
{
	public EmpireCraft(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
