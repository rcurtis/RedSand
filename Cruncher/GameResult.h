#pragma once

#include <string>
#include <vector>

namespace Cruncher
{

	class GameResult
	{
	public:
		GameResult();
		~GameResult();

		std::string Reels;
		std::vector<int> FullBallDraw;
		int NumberBallsDrawnForMatch = 0;
		std::vector<int> CardHitPattern;
		int CreditsPaidSingleBet = 0;
		std::vector<int> AmountsPerWin;
		int Freespins = 0;
		std::vector<int> LinesWon;
		int MonetizedWin = 0;
		std::vector<int> SymbolCountForWin;
		std::vector<char> SymbolForWin;
		int Win = 0;
		int ProgressiveNumber = 0;
	};

}