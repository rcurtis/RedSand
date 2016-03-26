#pragma once
#include <string>

namespace Cruncher
{
	class Spot
	{
		friend class BingoCard;
		friend class BingoGame;
		friend class Cruncher;

	public:
		Spot();
		~Spot();

		inline operator std::string() const
		{
			return "value: " + std::to_string(m_value) + ", daubed: " + std::to_string(m_daubed);
		}

	private:
		int m_value = -1;
		bool m_daubed = false;
	};

}
