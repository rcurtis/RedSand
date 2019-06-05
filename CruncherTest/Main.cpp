#include <iostream>
#include "../Cruncher/Cruncher.h"
#include "../Utils/Log.h"
#include "../Utils/PerformanceTimer.h"
#include "../Cruncher/BingoCard.h"
#include "../Cruncher/BingoBallDraw.h"
#include "../Cruncher/PTRandom.h"

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

	const int GAMES_COUNT = 100;

	Utils::PerformanceTimer game_timer{ "Finished playing 100 games" };
	for (int i = 0; i < GAMES_COUNT; i++)
	{
		auto rng = std::make_shared<Cruncher::PTRandom>();
		Cruncher::BingoBallDraw draw(rng);
		draw.Generate(25);

		auto result = c.Play(card, draw, 20);

		//log->info() << "Game result: " << result;
	}	
	game_timer.Expire();

	{
		Utils::PerformanceTimer t2{ "Finished clearing table data" };
		c.ClearTables();
	}
	
	system("pause");

	log->info("Main thread exiting");
}
