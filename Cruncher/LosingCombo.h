#pragma once
#include <string>

namespace Cruncher
{
	class LosingCombo
	{
	friend class LosingCombos;

	public:
		LosingCombo();
		~LosingCombo();

	private:
		std::string Reels;
	};

}