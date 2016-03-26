#include <iostream>
#include "../Cruncher/Cruncher.h"
#include "../Utils/Log.h"
#include "../Utils/PerformanceTimer.h"
#include "../Cruncher/BingoCard.h"
#include "../Cruncher/BingoBallDraw.h"

void main()
{
	Utils::Log::Init("C:/Logs/cruncherTest");
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

	Cruncher::BingoCard card{ std::vector<int>
	{ 1, 2, 3, 4, 5,
	6, 7, 8, 9, 10,
	11, 12, 13, 14, 15,
	16, 17, 18, 19, 20,
	21, 22, 23, 24, 25 } };

	Cruncher::BingoBallDraw draw;
	draw.SetBalls(std::vector<int>
	{ 25, 24, 20, 19, 5,
	6, 7, 8, 9, 10,
	11, 12, 13, 14, 15,
	16, 17, 18, 4, 3,
	21, 22, 23, 2, 1 });

	auto result = c.Play(card, draw, 20);

	log->info() << "Game result: " << result;

	Utils::PerformanceTimer t2{ "Finished clearing table data" };
	c.ClearTables();
	t2.Expire();

	system("pause");

	log->info("Main thread exiting");
}