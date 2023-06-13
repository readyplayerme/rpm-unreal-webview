// Copyright © 2021++ Ready Player Me

#pragma once

#include "WebBrowser.h"
#include "RpmWebBrowserTypes.h"
#include "RpmWebBrowserWidget.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RPMWEBBROWSER_API URpmWebBrowserWidget : public UWebBrowser
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Setup Browser"), Category = "Ready Player Me|Web Browser")
	void SetupBrowser();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Bind Browser To Object"),
		Category = "Ready Player Me|Web Browser")
	void BindBrowserToObject();

	void HandleEvents(const FString& JsonResponse) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ready Player Me|Web Browser")
	FString PartnerDomain = "demo";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ready Player Me|Web Browser")
	bool bClearCache = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ready Player Me|Web Browser")
	bool bQuickStart = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ready Player Me|Web Browser")
	ESelectBodyType SelectBodyType = ESelectBodyType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ready Player Me|Web Browser")
	ESelectGender SelectGender = ESelectGender::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ready Player Me|Web Browser")
	ELanguage Language = ELanguage::Default;
	
	UFUNCTION(BlueprintCallable, Category = "Ready Player Me|Web Browser")
	void EventReceived(const FString JsonResponse);

	UPROPERTY(BlueprintAssignable)
	FOnAvatarCreated OnAvatarExported;

	UPROPERTY(BlueprintAssignable)
	FOnUserSet OnUserSet;

	UPROPERTY(BlueprintAssignable)
	FOnAssetUnlock OnAssetUnlock;

	UPROPERTY(BlueprintAssignable)
	FOnUserAuthorized OnUserAuthorized;

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	void AddBodyTypeParam(TArray<FString>& Params) const;
	void AddGenderParam(TArray<FString>& Params) const;
	FString BuildUrl(const FString& LoginToken = FString()) const;
};
