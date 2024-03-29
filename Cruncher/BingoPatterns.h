#pragma once
#include <string>
#include <memory>
#include <vector>

namespace Cruncher
{
	class BingoPattern;

	class BingoPatterns
	{
		friend class BingoGame;

	public:
		explicit BingoPatterns(const std::string& filePath);
		~BingoPatterns();
		void Load();

	private:
		std::vector<std::unique_ptr<BingoPattern>> m_patterns;
		std::string m_filePath;
		int m_progressiveBase;
	};

}
