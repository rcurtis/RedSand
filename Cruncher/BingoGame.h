#pragma once
#include "BingoPatterns.h"
#include "BingoPattern.h"

namespace Cruncher
{
	class BingoCard;
	class BingoBallDraw;

	class BingoGame
	{
	public:
		BingoGame();
		~BingoGame();

		std::shared_ptr<BingoPattern> Play(BingoCard card, BingoBallDraw draw, const BingoPatterns& patterns, int& ballsDrawn);
	};

}