#pragma once

#include <iostream>
#include "../Cruncher/Cruncher.h"
#include "../Utils/Log.h"
#include "../Utils/PerformanceTimer.h"
#include "../Cruncher/BingoCard.h"
#include "../Cruncher/BingoBallDraw.h"

void main()
{
	Utils::Log::Init("C:/Logs/log");
	auto log = Utils::Log::Get("Main");
	log->info("Starting up main thread");

	system("pause");

	log->info("Main thread exiting");
}