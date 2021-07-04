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
//����˵�����ڹ涨��ʱ�䵽��һ��ʱ����ִ������ڵ㣬��ȫ����ʱ����ִ����һ����ڵ�
/**
 *
 */
UCLASS()
class LEARNBP_API ULatentFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//ExpandEnumAsExecs ��������Ű���ö������չ��������ӵ��ַ�����Ӧ�β�ExecType��ͬʱExecType�������������
	//Latent ��ʾ��Latent����
	//LatentInfo ����ӵ��ַ�����Ӧ�β�MyLatentInfo��ͬʱMyLatentInfo�������������
	//HidePin �����������ţ���д��Ӱ�칦�ܡ�ע�����һ��ʼûдHidePin��Ȼ������ͼ�����ڵ㡣Ȼ���ټ�HidePin�ٱ��룬���ʱ���Ѿ������õ���ͼ�ڵ㲻��仯��
	//DefaultToSelf ��WorldContextObjectĬ��ֵ��ΪSelf����д��Ӱ�칦��
	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "ExecType", Latent, LatentInfo = "MyLatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static void TwiceDelay(UObject* WorldContextObject, DELAY_EXEC& ExecType, FLatentActionInfo MyLatentInfo, float Duration);
};
