#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaArrayTest, "Beluga.Array", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

	bool FBelugaArrayTest::RunTest(const FString& Parameters)
{
	TArray<int32> arr = { 1, 2, 3 };

	arr.Add(5);

	TestEqual(TEXT("FArray"), arr, { 1, 2, 3, 5 });

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMapTest, "Beluga.Map", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

	bool FBelugaMapTest::RunTest(const FString& Parameters)
{
	TMap<FName, FString> map = { {TEXT("A"), TEXT("Apple")}, { TEXT("B"), TEXT("Banana") }, { TEXT("C"), TEXT("Cherry") } };
	
	map.Add({TEXT("D"), TEXT("Dekopon")});

	TMap<FName, FString> map2 = { {TEXT("A"), TEXT("Apple")}, { TEXT("B"), TEXT("Banana") }, { TEXT("C"), TEXT("Cherry") }, {TEXT("A"),TEXT("Dekopon")} };
	map2.Empty();

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaSetTest, "Beluga.Set", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

	bool FBelugaSetTest::RunTest(const FString& Parameters)
{
	TSet<int32> set = { 1,2,3 };

	set.Add(1);
	return true;
}