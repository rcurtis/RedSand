#pragma once
#include <string>
#include <vector>
#include <map>
#include "BingoPatterns.h"
#include "WinningCombos.h"
#include "LosingCombos.h"

namespace Cuncher 
{
	class Cruncher
	{
	public:
		Cruncher();
		~Cruncher();

		void LoadPaytable(const std::string& fileName);
		void LoadPaytables(std::vector<std::string>& fileNames);
		void ResetPaytables();

	private:
		std::map<std::string, ::Cruncher::BingoPatterns> m_loadedBingoPatterns;
		std::map<std::string, ::Cruncher::WinningCombos> m_loadedWinningCombos;
		std::map<std::string, ::Cruncher::LosingCombos> m_loadedlosingCombos;
	};
}
