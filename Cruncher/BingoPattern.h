#pragma once
#include <ostream>

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
		friend class Cruncher;
	public:
		BingoPattern();
		~BingoPattern();

		friend std::ostream& operator<<(std::ostream& os, const BingoPattern& obj)
		{
			return os
				<< "m_pattern: " << obj.m_pattern
				<< " m_freespins: " << obj.m_freespins
				<< " m_monetizedWin: " << obj.m_monetizedWin
				<< " m_ballsToMatch: " << obj.m_ballsToMatch
				<< " m_creditsPaidMaxBet: " << obj.m_creditsPaidMaxBet
				<< " m_creditsPaidSingleBet: " << obj.m_creditsPaidSingleBet
				<< " m_progressiveNumber: " << obj.m_progressiveNumber;
		}

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
