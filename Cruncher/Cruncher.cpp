#include "Cruncher.h"
#include <algorithm>
#include <string>
#include "../Utils/Log.h"


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

}