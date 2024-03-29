#pragma once
#include <string>
#include <vector>
#include <map>
#include "BingoPatterns.h"
#include "WinningCombos.h"
#include "LosingCombos.h"
#include <memory>
#include "GameResult.h"

namespace Cruncher 
{
	class BingoBallDraw;
	class BingoCard;

	class Cruncher
	{
	public:
		Cruncher();
		~Cruncher();

		GameResult Play(BingoCard card, BingoBallDraw balldraw, int lines);
		void LoadPaytable(const std::string& fileName);
		void LoadPaytables(std::vector<std::string>& fileNames);
		void ClearTables();

	private:
		std::map<std::string, std::unique_ptr<BingoPatterns>> m_loadedBingoPatterns;
		std::map<std::string, std::unique_ptr<WinningCombos>> m_loadedWinningCombos;
		std::map<std::string, std::unique_ptr<LosingCombos>> m_loadedLosingCombos;

		GameResult GetWinnerResultFromCombo(WinningCombo* combo, 
			BingoBallDraw& balldraw, BingoCard& card, int numberBallsDrawn);
		GameResult GetLoserResultFromCombo(LosingCombo* combo, 
			BingoBallDraw& balldraw, BingoCard& card, int numberBallsDrawn);

		void ParseToIntVector(std::vector<int>& out, std::string& str);
		void StripSpaces(std::string& in);
	};
}
