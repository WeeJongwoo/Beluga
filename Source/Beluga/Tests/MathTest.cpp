#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{
	FVector vec;
	FVector vec2 = vec;
	FVector vec3 = FVector(3, 0, 0);

	vec2 = FVector::UpVector;
	vec3 = FVector::UpVector;

	TestEqual(TEXT("UpVector"), vec2, vec3);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaRotatorTest, "Beluga.Rotator", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaRotatorTest::RunTest(const FString& Parameters)
{
	FRotator rot(FRotator::ZeroRotator);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMatrixTest, "Beluga.Matrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMatrixTest::RunTest(const FString& Parameters)
{
	FMatrix mat = FMatrix::Identity;

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTransformTest, "Beluga.Transform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTransformTest::RunTest(const FString& Parameters)
{
	FTransform trans;
	FQuat rotation(2.0, 3.0, 4.0, 0.0);
	FVector position(4.0,3.2,4.5);
	FVector scale(3.0, 3.0, 3.0);

	trans.TransformPosition(position);
	trans.TransformRotation(rotation);
	trans.ScaleTranslation(scale);

	return true;
}