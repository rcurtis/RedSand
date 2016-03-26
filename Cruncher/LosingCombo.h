#pragma once
#include <string>

namespace Cruncher
{
	class LosingCombo
	{
	friend class LosingCombos;
	friend class Cruncher;

	public:
		LosingCombo();
		~LosingCombo();

	private:
		std::string Reels;
	};

}