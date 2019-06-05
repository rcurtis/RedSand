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

		BingoPattern Play(BingoCard& card, BingoBallDraw draw, 
			BingoPatterns* patterns, int& ballsDrawn);
	};

}