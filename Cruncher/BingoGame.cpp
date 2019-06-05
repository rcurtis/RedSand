#include "BingoGame.h"
#include "BingoCard.h"
#include "BingoBallDraw.h"
#include "BingoPatterns.h"
#include "BingoPattern.h"
#include <algorithm>
#include <memory>

namespace Cruncher
{

	BingoGame::BingoGame()
	{
	}


	BingoGame::~BingoGame()
	{
	}

	BingoPattern BingoGame::Play(BingoCard& card, BingoBallDraw draw, BingoPatterns* patterns, int& ballsDrawn)
	{
		ballsDrawn = 1;
		for (const auto& ball : draw.GetBalls())
		{
			auto daubedChanged = false;
			for (auto& spot : card.GetSpots())
			{
				if (spot.m_value == ball)
				{
					spot.m_daubed = true;
					daubedChanged = true;
				}
			}

			if (daubedChanged)
			{
				daubedChanged = false;
				auto hitsBitField = card.GetDaubBitPattern();

				auto& pat = patterns->m_patterns;
				std::vector <BingoPattern*> found;
				std::for_each(pat.begin(), pat.end(), [&found, &hitsBitField, &ballsDrawn](std::unique_ptr<BingoPattern>& entry)
				//for (auto& entry : pat)
				{
					bool matchingPattern = (entry->m_pattern & hitsBitField) == entry->m_pattern;
					bool matchingBallsDrawn = ballsDrawn == entry->m_ballsToMatch;
					if (matchingPattern && matchingBallsDrawn)
					{
						found.push_back(entry.get());
					}
				});

				if (found.size() > 0)
				{
					auto retval = found.front();
					return *retval;
				}
			}
			ballsDrawn++;
		}
		ballsDrawn--;
		BingoPattern loser;
		loser.m_monetizedWin = 0;
		return loser;
	}
}
