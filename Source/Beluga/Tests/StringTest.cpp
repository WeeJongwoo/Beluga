#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	int32 a = 3;
	int32 b = 3;

	TestTrue(TEXT("Always FAIL!"), true);
	//TestEqual(TEXT("Always FAIL!"), a,b);

	{
		FStringFormatNamedArguments NamedArgs;
		NamedArgs.Add(TEXT("First"), 123);
		NamedArgs.Add(TEXT("Second"), 1.0f);
		NamedArgs.Add(TEXT("Third"), TEXT("string"));

		TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
	}

	{
		FStringFormatOrderedArguments OrderedArgs;
		OrderedArgs.Add(123);
		OrderedArgs.Add(1.0f);
		OrderedArgs.Add(TEXT("string"));

		TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));


	}

	{
		FString out = FString::Format(TEXT("{0} {1} {2}"), { 123, 1.0f, TEXT("string")});
	}


	return true;
}