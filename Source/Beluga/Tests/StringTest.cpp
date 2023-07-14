#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool isRabbit(FName Check)
{
	static const FName NAME_Rabbit(TEXT("Rabbit"));
	return Check == NAME_Rabbit;
}

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	FString strChar("char");
	FString strWChar(L"wchar");
	FString strTChar(TEXT("Tchar"));

	// 길이 구하기
	{
		FString str(TEXT("str"));
		int32 LenStr = str.Len();
		check(LenStr == 3);
	}
	// Replace
	{
		FString str(TEXT("str"));
		FString result = str.Replace(TEXT("st"), TEXT("ds"));
		check(result == TEXT("dsr"));
	}
	// InsertAt

	// clear

	// Split

	//Operator
	{
		FString strApple(TEXT("Apple"));
		FString strBanana(TEXT("Banana"));
		{
			TestEqual(TEXT("Operator []"), strApple[2], L'p');
		}

		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
	}

	// IsEmpty
	{
		FString str1(TEXT("qwerasdf"));
		FString str2(TEXT(""));
		check(!(str1.IsEmpty()));
		check(str2.IsEmpty());
	}
	// Shrink
	{
		FString str(TEXT("qwerasdfzxcv"));
		str.Reserve(100);

		int32 Reserved = str.GetAllocatedSize();

		str.Shrink();

		int32 Shrinked = str.GetAllocatedSize();
		
		TestFalse(TEXT("Shrink "), Reserved == Shrinked);
	}
	// RemoveAt
	{
		FString str(TEXT("qwerasdf"));
		str.RemoveAt(3, str.Len() - 3);
		check(str == TEXT("qwe"));
	}

	// find 로 인덱스
	{
		FString str(TEXT("qwerasdf"));
		int32 index;
		index = str.Find("e");

		TestTrue(TEXT("Find "), index == 2);
	}
	// Left
	{
		FString str(TEXT("qwerasdfzxcv"));
		FString out = str.Left(4);
		check(out == TEXT("qwer"));
	}
	// Mid
	{
		FString str(TEXT("qwerasdfzxcv"));
		FString out = str.Mid(4);
		check(out == TEXT("asdfzxcv"));
	}
	// Right
	{
		FString str(TEXT("qwerasdfzxcv"));
		FString out = str.Right(4);
		check(out == TEXT("zxcv"));
	}

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
		
		TestEqual(TEXT("Format"), out, TEXT("123 1.000000 string"));
	}

	{
		FName test(TEXT("Rabbit"));
		bool bRabbit = isRabbit(test);
		
		TestTrue(TEXT("Rabbit"), bRabbit);
	}

	return true;
}