#pragma once

#include <iostream>
#include "../Cruncher/WinningCombos.h"
#include "../Cruncher/LosingCombos.h"
#include "../Cruncher/BingoPatterns.h"
#include "../Utils/Log.h"
#include <string>

void main()
{
	Utils::Log::Init("C:/Logs/log");
	auto log = Utils::Log::Get("Main");
	log->info("Starting up main thread");

	Cruncher::WinningCombos winners("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_25_line.xml");
	winners.Load();

	Cruncher::LosingCombos losers("D:/gamewarrior/Config/BINGO/25Line/94/L25Line_25_line.xml");
	losers.Load();

	Cruncher::BingoPatterns patterns("D:/gamewarrior/Config/BINGO/25Line/94/25Line_25_line.xml");
	patterns.Load();

	system("pause");

	log->info("Main thread exiting");
}