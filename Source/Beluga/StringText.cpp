#include "BelugaMinimal.h"

void StringTest() 
{
	
	// 생성
			// char		"asdf"
			// wchar	L"asdf"
			// tchar	TEXT("asdf")

		// 대입 연산자 = 

		// Printf

		// Format

			// FStringFormatNamedArguments
			// FStringFormatOrderedArguments
		

		// operator []

		// 대소비교

		// TCHAR* 얻기
		// operator*

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
		// Insert

		// clear

		// Split

		// IsEmpty
		{
			FString str1(TEXT("qwerasdf"));
			FString str2(TEXT(""));
			//check(str1.IsEmpty());
			check(str2.IsEmpty());
		}
		// Shrink

		// RemoveAt
		{
			FString str(TEXT("qwerasdf"));
			str.RemoveAt(3,str.Len()-3);
			check(str == TEXT("qwe"));
		}

		// find 로 인덱스
		{
			FString str(TEXT("qwerasdf"));
			//int32 index;
			//index = Find("e", str);
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
		// 대문자로 변환, 소문자로 변환
}
		
