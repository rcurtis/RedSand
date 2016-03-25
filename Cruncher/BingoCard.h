#pragma once

#include <vector>
#include "Spot.h"

namespace Cruncher
{

	class BingoCard
	{
	public:
		explicit BingoCard(std::vector<int> values);
		explicit BingoCard(std::vector<Spot> spots);
		~BingoCard();

		int NumberOfDaubs();
		void ClearDaubs();
		int GetDaubBitPattern();
		void PrintDebugGraph();
		void PrintBitmapGraph();
		static std::vector<std::vector<int>> RotateRight(std::vector<std::vector<int>>& matrix, int width);
		std::vector<Spot>& GetSpots();

	private:
		std::vector<Spot> m_spots;
		std::vector<int> m_pattern;
	};	
}
