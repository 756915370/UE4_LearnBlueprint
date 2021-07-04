// Fill out your copyright notice in the Description page of Project Settings.

#include "LatentFunctionLibrary.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"


class FTwiceDelayAction : public FPendingLatentAction
{
public:
	float TotalTime;
	float TimeRemaining;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	DELAY_EXEC& ExecTypeRef;
	bool bHalfTriggerd = false;

	FTwiceDelayAction(float Duration, const FLatentActionInfo& LatentInfo, DELAY_EXEC& ExecType)
		:TotalTime(Duration), TimeRemaining(Duration), ExecutionFunction(LatentInfo.ExecutionFunction), OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget), ExecTypeRef(ExecType)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		TimeRemaining -= Response.ElapsedTime();
		if (TimeRemaining < TotalTime / 2.0f && !bHalfTriggerd)
		{
			ExecTypeRef = DELAY_EXEC::HalfExec;
			Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
			bHalfTriggerd = true;
		}
		else if (TimeRemaining < 0.0f)
		{
			ExecTypeRef = DELAY_EXEC::CompleteExec;
			Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
			Response.DoneIf(true);
		}
	}
};

void ULatentFunctionLibrary::TwiceDelay(UObject* WorldContextObject, DELAY_EXEC& ExecType, FLatentActionInfo MyLatentInfo,
	float Duration)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FTwiceDelayAction>(MyLatentInfo.CallbackTarget, MyLatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(MyLatentInfo.CallbackTarget, MyLatentInfo.UUID, new FTwiceDelayAction(Duration, MyLatentInfo, ExecType));
		}
	}
}
