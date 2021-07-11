  
// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class LearnBPEditor : ModuleRules
{
	public LearnBPEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "UnrealEd",
            "Slate",
            "SlateCore",
            "EditorStyle",
            "GraphEditor",
            "BlueprintGraph",
            "KismetCompiler",
            "LearnBP"
        });

    }
}