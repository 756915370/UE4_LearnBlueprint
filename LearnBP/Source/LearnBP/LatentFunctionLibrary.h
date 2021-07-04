// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "LatentFunctionLibrary.generated.h"

UENUM()
enum class DELAY_EXEC : uint8
{
	HalfExec,
	CompleteExec
};

//blog:https://programmersought.com/article/95054347848/
//功能说明：在规定的时间到达一半时可以执行输出节点，完全到达时可以执行另一输出节点
/**
 *
 */
UCLASS()
class LEARNBP_API ULatentFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//ExpandEnumAsExecs 将输出引脚按照枚举类型展开，后面接的字符串对应形参ExecType，同时ExecType将不会出现引脚
	//Latent 表示是Latent方法
	//LatentInfo 后面接的字符串对应形参MyLatentInfo，同时MyLatentInfo将不会出现引脚
	//HidePin 隐藏输入引脚，不写不影响功能。注意如果一开始没写HidePin，然后在蓝图创建节点。然后再加HidePin再编译，这个时候已经创建好的蓝图节点不会变化。
	//DefaultToSelf 将WorldContextObject默认值设为Self，不写不影响功能
	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "ExecType", Latent, LatentInfo = "MyLatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static void TwiceDelay(UObject* WorldContextObject, DELAY_EXEC& ExecType, FLatentActionInfo MyLatentInfo, float Duration);
};
