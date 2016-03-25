#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Cruncher/Cruncher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CruncherTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(TestCruncherMethod)
		{
			Cuncher::Cruncher c;
			Assert::IsTrue(c.ShouldBeTrue());
		}

	};
}