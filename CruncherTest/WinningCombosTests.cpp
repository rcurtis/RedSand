#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Cruncher/Cruncher.h"
#include "../Cruncher/WinningCombos.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CruncherTest
{
	TEST_CLASS(WinningCombosTests)
	{
	public:

		TEST_METHOD(ShouldLoadWinningFiles)
		{
			try
			{
				Cruncher::WinningCombos combos("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_25_line.xml");
				combos.Load();
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	};
}