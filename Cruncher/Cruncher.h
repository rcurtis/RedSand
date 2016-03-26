#pragma once
#include <string>
#include <vector>
#include <map>
#include "BingoPatterns.h"
#include "WinningCombos.h"
#include "LosingCombos.h"
#include <memory>

namespace Cruncher 
{
	class Cruncher
	{
	public:
		Cruncher();
		~Cruncher();

		void LoadPaytable(const std::string& fileName);
		void LoadPaytables(std::vector<std::string>& fileNames);
		void ClearTables();

	private:
		std::map<std::string, std::shared_ptr<BingoPatterns>> m_loadedBingoPatterns;
		std::map<std::string, std::shared_ptr<WinningCombos>> m_loadedWinningCombos;
		std::map<std::string, std::shared_ptr<LosingCombos>> m_loadedLosingCombos;
	};
}
