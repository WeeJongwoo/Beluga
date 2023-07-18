#include "DuckCreature.h"

void UDuckCreature::Init()
{

}

FString UDuckCreature::CPP_Hello()
{
	return HelloMsg;
}

FName UDuckCreature::CPP_GetName()
{
	return Name;
}

void UDuckCreature::BOTH_Update_Implementation()
{
	HelloMsg = HelloMsg.ToUpper();
}