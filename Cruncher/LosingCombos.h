#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Cruncher
{
	class LosingCombo;

	class LosingCombos
	{
	public:
		explicit LosingCombos(const std::string& filePath);
		~LosingCombos();
		void Load();

	private:
		std::vector<std::shared_ptr<LosingCombo>> m_combos;
		std::string m_filePath;
	};

}