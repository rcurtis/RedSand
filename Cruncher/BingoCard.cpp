#include "BingoCard.h"
#include <algorithm>
#include "../Utils/Log.h"
#include <string>

namespace Cruncher
{
	
	BingoCard::BingoCard(std::vector<int> values)
	{
		for (int i = 0; i < 25; i++)
		{
			Spot spot;
			spot.m_value = values[i];
			m_spots.push_back(spot);
		}
	}

	BingoCard::BingoCard(std::vector<Spot> spots)
	{
		m_spots = std::vector<Spot>(spots.size());
		std::copy(spots.begin(), spots.end(), m_spots.begin());
	}

	int BingoCard::NumberOfDaubs()
	{
		int daubs = std::count_if(m_spots.begin(), m_spots.end(), [](Spot& spot){ return spot.m_daubed; });
		return daubs;
	}

	void BingoCard::ClearDaubs()
	{
		std::for_each(m_spots.begin(), m_spots.end(), [](Spot& spot) { spot.m_daubed = false; });
	}

	int BingoCard::GetDaubPattern()
	{
		// Lots of scary stuff happening here.  This was a direct port of the C# version of this algorithm.
		// If we change our representation of bingo cards from a vector<int> to a multi-dimensional array or vector
		// then this code gets a lot simpler.
		std::vector<int> bits; 
		std::for_each(m_spots.begin(), m_spots.end(), [&bits](Spot& spot){ bits.push_back(spot.m_daubed ? 1 : 0); });

		static auto cardWidth = 5;

		std::vector<std::vector<int>> matrix(cardWidth, std::vector<int>(cardWidth));
		auto count = 0;
		for (int i = 0; i < cardWidth; i++)
		{
			for (int j = 0; j < cardWidth; j++)
			{
				auto value = bits[count];
				matrix[i][j] = value;
				count++;
			}
		}

		matrix = RotateRight(matrix, cardWidth);
		matrix = RotateRight(matrix, cardWidth);

		std::vector<int> flattened;
		for (int i = 0; i < cardWidth; i++)
		{
			for (int j = 0; j < cardWidth; j++)
			{
				flattened.push_back(matrix[i][j]);
			}
		}

		auto accum = 0;
		for (int i = 0; i < flattened.size(); i++)
		{
			auto position = flattened.size() - i - 1;
			auto increment = flattened[i] << position;
			accum += increment;
		}

		return accum;
	}

	void BingoCard::PrintDebugGraph()
	{
		auto log = Utils::Log::Get("BingoCard");

		std::string row = "";
		for (int i = 0; i < m_spots.size(); i++)
		{
			if (i%5 == 0)
			{
				log->info() << row;
				row = "";
			}
			row += std::to_string(m_spots[i].m_value) + ", ";
		}
		log->info() << row;
	}

	void BingoCard::PrintBitmapGraph()
	{
		auto log = Utils::Log::Get("BingoCard");

		std::string row = "";
		for (int i = 0; i < m_spots.size(); i++)
		{
			if (i % 5 == 0)
			{
				log->info() << row;
				row = "";
			}
			row += std::to_string(m_spots[i].m_daubed ? 1 : 0) + ", ";
		}
		log->info() << row;
	}

	std::vector<std::vector<int>> BingoCard::RotateRight(std::vector<std::vector<int>>& matrix, int width)
	{
		std::vector<std::vector<int>> ret(width, std::vector<int>(width));
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < width; j++)
			{
				ret[i][j] = matrix[width - j - 1][i];
			}
		}
		return ret;
	}

	BingoCard::~BingoCard()
	{
	}

}