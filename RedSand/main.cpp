#pragma once

#include <iostream>
#include "../Cruncher/Cruncher.h"
#include "../Utils/Log.h"
#include "../Utils/PerformanceTimer.h"

void main()
{
	Utils::Log::Init("C:/Logs/log");
	auto log = Utils::Log::Get("Main");
	log->info("Starting up main thread");

	Cruncher::Cruncher c;

	Utils::PerformanceTimer t1{ "Finished loading all tables " };
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_25_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_20_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_10_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_5_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/W25Line_1_line.xml");

	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/L25Line_25_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/L25Line_20_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/L25Line_10_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/L25Line_5_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/L25Line_1_line.xml");

	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/25Line_25_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/25Line_20_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/25Line_10_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/25Line_5_line.xml");
	c.LoadPaytable("D:/gamewarrior/Config/BINGO/25Line/94/25Line_1_line.xml");
	t1.Expire();

	Utils::PerformanceTimer t2{ "Finished clearing table data" };
	c.ClearTables();
	t2.Expire();

	system("pause");

	log->info("Main thread exiting");
}