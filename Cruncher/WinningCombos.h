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
	public:
		explicit WinningCombos(const std::string& filePath);
		~WinningCombos();
		void Load();

	private:
		std::multimap<long, std::shared_ptr<WinningCombo>> m_combos;
		std::string m_filePath;
	};
}
