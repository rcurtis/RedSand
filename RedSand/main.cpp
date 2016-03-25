#pragma once

#include <iostream>
#include "../Cruncher/WinningCombos.h"
#include "../Utils/Log.h"
#include <string>

void main()
{
	Utils::Log::Init("C:/Logs/log");
	auto log = Utils::Log::Get("Main");
	log->info("Starting up main thread");

	Cruncher::WinningCombos combos("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_25_line.xml");
	combos.Load();
	system("pause");

	log->info("Main thread exiting");
}