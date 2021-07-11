// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LearnBPEditorTarget : TargetRules
{
	public LearnBPEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange(new string[] {
			"LearnBP",
			"LearnBPEditor"});
	}
}
