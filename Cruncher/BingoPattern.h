#pragma once

namespace Cruncher
{

	enum class BonusType
	{
		FREESPINS,
		WHATEVERELSEDUMBSHITWEWANTTOGOHERE
	};

	class BingoPattern
	{
		friend class BingoPatterns;
		friend class BingoGame;
	public:
		BingoPattern();
		~BingoPattern();

	private:
		// this number can only be 2^25, so 31 bits should be more than
		// enough to accomodate.  If we ever go to large bingo cards, this
		// will have to be reconsidered.
		int m_pattern;
		int m_freespins;
		int m_monetizedWin;
		int m_ballsToMatch;
		int m_creditsPaidMaxBet;
		int m_creditsPaidSingleBet;
		int m_progressiveNumber = 0;
	};

}