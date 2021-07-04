// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Http.h"
#include "BlueprintAsyncHttpRequest.generated.h"

//blog:https://neil3d.gitee.io/unreal/bp-async.html
//����˵�����Զ���һ��Http���ͺͽ��ܵ���ͼ�첽�ڵ�
//�첽�ڵ��LatentFunction��һ���ĵط�����
//1.LatentFunction�����ϻ�����֡���ã�Ȼ���ж�����
//2.�첽�ڵ����������첽��ͬʱ������ͬ��ִ�е��������
//3.�ں�������Ȼ����ʹ���첽�ڵ㵫�ǹ��ܻ����ޣ�ֻ��ʹ������ͬ��������ţ��첽���ܲ����á���LantentFunction�ں���������ȫ����ʹ�á�
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
