#include "Cruncher.h"
#include <algorithm>
#include <string>
#include "../Utils/Log.h"
#include "BingoBallDraw.h"
#include "BingoCard.h"
#include "BingoGame.h"
#include "GameResult.h"
#include "WinningCombo.h"
#include "LosingCombo.h"
#include <sstream>

namespace Cruncher
{

	Cruncher::Cruncher()
	{
	}

	void Cruncher::LoadPaytable(const std::string& fileName)
	{
		auto log = Utils::Log::Get("LoadPaytable");

		if (m_loadedBingoPatterns.count(fileName)
			|| m_loadedWinningCombos.count(fileName)
			|| m_loadedLosingCombos.count(fileName))
		{
			return;
		}

		std::string lookingFor = "/";
		auto last = std::find_end(fileName.begin(), fileName.end(), lookingFor.begin(), lookingFor.end());

		if (last == fileName.end())
			throw "Could not parse paytable fileName";

		auto firstChar = *(std::next(last));
		if (firstChar == 'W')
		{
			auto combos = std::make_shared<WinningCombos>(fileName);
			combos->Load();
			m_loadedWinningCombos.insert({ fileName, combos });
		}
		else if (firstChar == 'L')
		{
			auto combos = std::make_shared<LosingCombos>(fileName);
			combos->Load();
			m_loadedLosingCombos.insert({ fileName, combos });
		}
		else if (firstChar == '2')
		{
			auto combos = std::make_shared<BingoPatterns>(fileName);
			combos->Load();
			m_loadedBingoPatterns.insert({ fileName, combos });
		}
		else
		{
			std::string msg = "Usuported paytable name: " + fileName;
			log->info() << msg;
			throw msg;
		}

	}

	void Cruncher::LoadPaytables(std::vector<std::string>& fileNames)
	{
		for (const auto& fileName : fileNames)
		{
			LoadPaytable(fileName);
		}
	}

	void Cruncher::ClearTables()
	{
		m_loadedBingoPatterns.clear();
		m_loadedLosingCombos.clear();
		m_loadedWinningCombos.clear();
	}

	Cruncher::~Cruncher()
	{
	}

	void Cruncher::ParseToIntVector(std::vector<int>& out, std::string& str)
	{
		std::stringstream ss{ str };
		int i;
		while (ss >> i)
		{
			out.push_back(i);
		}
	}

	void Cruncher::StripSpaces(std::string& in)
	{
		in.erase(std::remove_if(in.begin(), in.end(), std::isspace), in.end());
	}

	GameResult Cruncher::GetWinnerResultFromCombo(std::shared_ptr<WinningCombo> combo,
		BingoBallDraw& balldraw, BingoCard& card, int numberBallsDrawn)
	{
		GameResult result;
		result.CreditsPaidSingleBet = combo->Win;		
		
		ParseToIntVector(result.AmountsPerWin, combo->AmountsPerWin);	

		result.Freespins = combo->Freespins;

		ParseToIntVector(result.LinesWon, combo->LinesWon);

		result.MonetizedWin = combo->MonetizedWin;
		result.Reels = combo->Reels;

		ParseToIntVector(result.SymbolCountForWin, combo->SymbolCountForWin);

		result.SymbolForWin = combo->SymbolForWin;

		StripSpaces(result.SymbolForWin);

		result.Win = combo->Win;
		result.ProgressiveNumber = combo->ProgressiveNumber;
		result.FullBallDraw = balldraw.m_balls;
		result.NumberBallsDrawnForMatch = numberBallsDrawn;

		for (auto& spot : card.m_spots)
		{
			auto daubed = spot.m_daubed ? 1 : 0;
			result.CardHitPattern.push_back(daubed);
		}
		return result;
	}

	GameResult Cruncher::GetLoserResultFromCombo(std::shared_ptr<LosingCombo> combo, 
		BingoBallDraw& balldraw, BingoCard& card, int numberBallsDrawn)
	{
		GameResult result;
		result.Reels = combo->Reels;
		result.FullBallDraw = balldraw.m_balls;
		result.NumberBallsDrawnForMatch = numberBallsDrawn;
		std::for_each(card.m_spots.begin(), card.m_spots.end(), [&result](Spot& spot)
		{
			result.CardHitPattern.push_back(spot.m_daubed ? 1 : 0);
		});
		return result;
	}

	// This function has grown way too big.  Break up it up into smaller functions.
	GameResult Cruncher::Play(BingoCard card, BingoBallDraw balldraw, int lines)
	{
		auto log = Utils::Log::Get("Cruncher");

		std::shared_ptr<BingoPatterns> patterns;
		std::string path;

		// TODO: Sort this out.  We need to find the correct pattern file for the lines.
		// This is not hard to do, just takes a bit of testing.
		//if (m_loadedBingoPatterns.size() == 1)
		//{
		auto first = (*m_loadedBingoPatterns.begin());
		patterns = first.second;
		path = first.first;
		//}

		if (path.empty())
		{
			std::string msg = "Failed to find bingo table for game";
			log->error() << msg;
			throw msg;
		}

		std::string splitter = "/";
		auto lastSplitter = std::find_end(path.begin(), path.end(), splitter.begin(), splitter.end());
		if (lastSplitter == path.end())
		{
			std::string msg = "Could not parse bingo table path in Cruncher::Play";
			log->error() << msg;
			throw msg;
		}
		
		std::string prefix;
		prefix.assign(path.begin(), lastSplitter);
		std::string postfix;
		postfix.assign(lastSplitter + 1, path.end());

		auto winnerTable = prefix + "/W" + postfix;
		auto loserTable = prefix + "/L" + postfix;

		if (!m_loadedWinningCombos.count(winnerTable))
		{
			std::string msg = "Could find winner table for game in progress: " + winnerTable;
			log->error() << msg;
			throw msg;
		}

		if (!m_loadedLosingCombos.count(loserTable))
		{
			std::string msg = "Could find loser table for game in progress: " + loserTable;
			log->error() << msg;
			throw msg;
		}

		BingoGame game;
		int numberBallsDrawn = -1;

		auto bingoResult = game.Play(card, balldraw, patterns, numberBallsDrawn);

		if (bingoResult->m_monetizedWin != 0)
		{
			// Winner
			auto winningTable = m_loadedWinningCombos[winnerTable];
			if (!winningTable)
			{
				std::string msg = "Error looking up winning table for game in progress: " + loserTable;
				log->error() << msg;
				throw msg;
			}

			auto combos = winningTable->m_combos;
			std::vector<std::shared_ptr<WinningCombo>> posibilities;
			std::for_each(combos.begin(), combos.end(), [&posibilities, &bingoResult](std::pair<long, std::shared_ptr<WinningCombo>> combos)
			{
				auto combo = combos.second;
				if (combo->Win == bingoResult->m_creditsPaidSingleBet
					&& combo->Freespins == bingoResult->m_freespins
					&& combo->ProgressiveNumber == bingoResult->m_progressiveNumber)
					posibilities.push_back(combo);
			});

			if (posibilities.empty())
			{
				std::string msg = "Could not find winning results for bingo game that has already been played! : ";
				log->error() << msg << bingoResult;
				throw msg;
			}

			// TODO: better rng here
			auto random = rand() % posibilities.size() - 1;

			auto outcome = posibilities[random];
			auto result = GetWinnerResultFromCombo(outcome, balldraw, card, numberBallsDrawn);
			return result;
		}
		else
		{
			// Loser	
			auto losingTable = m_loadedLosingCombos[loserTable];
			if (!losingTable)
			{
				std::string msg = "Error looking up losing table for game in progress: " + loserTable;
				log->error() << msg;
				throw msg;
			}

			// TODO: better rng here
			auto random = rand() % (losingTable->m_combos.size() - 1);
			auto outcome = losingTable->m_combos[random];

			auto result = GetLoserResultFromCombo(outcome, balldraw, card, numberBallsDrawn);
			return result;
		}
	}
}
