#pragma once

#include <string>
#include <map>
#include <memory>
#include <vector>


namespace Cruncher
{
	class WinningCombo;

	class WinningCombos
	{

		friend class Cruncher;
	public:
		explicit WinningCombos(const std::string& filePath);
		~WinningCombos();
		void Load();

	private:
		std::multimap<long, std::unique_ptr<WinningCombo>> m_combos;
		std::string m_filePath;
	};
}
