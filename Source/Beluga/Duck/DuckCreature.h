#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DuckCreature.generated.h"

/** Please add a class description */
UCLASS(Blueprintable, BlueprintType, Abstract)
class BELUGA_API UDuckCreature : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintCallable)
	FString CPP_Hello();

	UFUNCTION(BlueprintPure)
	FName CPP_GetName();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BP_SetHelloMessage();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void BOTH_Update();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString HelloMsg;

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FName Name;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 MaxHP;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default", Transient)
	int32 CurrentHP;
};
