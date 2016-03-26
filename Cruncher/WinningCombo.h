#pragma once

#include <string>

namespace Cruncher{

	class WinningCombo
	{
		friend class WinningCombos;
		friend class Cruncher;
	public:
		WinningCombo();
		~WinningCombo();
		
	private:
		std::string AmountsPerWin;
		int Freespins;
		std::string LinesWon;
		int MonetizedWin;
		std::string Reels;
		std::string SymbolCountForWin;
		std::string SymbolForWin;
		int Win;
		int ProgressiveNumber = 0;
	};

}