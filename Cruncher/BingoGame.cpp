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

	std::shared_ptr<BingoPattern> BingoGame::Play(BingoCard& card, BingoBallDraw draw, std::shared_ptr<BingoPatterns> patterns, int& ballsDrawn)
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

				auto pat = patterns->m_patterns;
				std::vector <std::shared_ptr<BingoPattern>> found;
				std::for_each(pat.begin(), pat.end(), [&found, &hitsBitField, &ballsDrawn](std::shared_ptr<BingoPattern> entry)
				{
					bool matchingPattern = (entry->m_pattern & hitsBitField) == entry->m_pattern;
					bool matchingBallsDrawn = ballsDrawn == entry->m_ballsToMatch;
					if (matchingPattern && matchingBallsDrawn)
						found.push_back(entry);
				});

				if (found.size() > 0)
				{
					auto retval = found.front();
					return retval;
				}
			}
			ballsDrawn++;
		}
		ballsDrawn--;
		auto loser = std::make_shared<BingoPattern>();
		loser->m_monetizedWin = 0;
		return loser;
	}
}
