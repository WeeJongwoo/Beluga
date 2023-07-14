#include "BelugaMinimal.h"
DEFINE_LOG_CATEGORY(LogBeluga);


bool isRabbit(FName Check)
{
	static const FName NAME_Rabbit(TEXT("Rabbit"));
	return Check == NAME_Rabbit;
}


class FBelugaModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FName test(TEXT("Rabbit"));
		bool bRabbit = isRabbit(test);
		UE_LOG(LogBeluga, Warning, TEXT("Rabbit : %i"), bRabbit);

		UE_LOG(LogBeluga, Display, TEXT("BelugaModule::StartupModule"));

		extern void StringTest();
		StringTest();
	}
	virtual void ShutdownModule() override
	{
		UE_LOG(LogBeluga, Display, TEXT("BelugaModule::ShutdownModule"));
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FBelugaModule, Beluga, "Beluga");