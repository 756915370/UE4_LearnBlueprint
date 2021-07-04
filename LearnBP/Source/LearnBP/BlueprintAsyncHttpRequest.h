// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Http.h"
#include "BlueprintAsyncHttpRequest.generated.h"

//blog:https://neil3d.gitee.io/unreal/bp-async.html
//功能说明：自定义一个Http发送和接受的蓝图异步节点
//异步节点和LatentFunction不一样的地方：、
//1.LatentFunction本质上还是逐帧调用，然后判断条件
//2.异步节点是真正的异步，同时它还有同步执行的输出引脚
//3.在函数内虽然可以使用异步节点但是功能会受限，只能使用它的同步输出引脚，异步功能不能用。而LantentFunction在函数里面完全不能使用。
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHttpResponseDelegatge, int32, Code, FString, Data);
/**
 *
 */
UCLASS()
class LEARNBP_API UBlueprintAsyncHttpRequest : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static UBlueprintAsyncHttpRequest* HttpRequest(const FString& URL);
	
	UPROPERTY(BlueprintAssignable)
		FHttpResponseDelegatge OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FHttpResponseDelegatge OnFail;

	void OnHttpResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void SendRequest(const FString& URL);
};
