#pragma once
#include "IRandom.h"

namespace Cruncher
{

	class PTRandom : public IRandom
	{
	public:
		PTRandom();
		~PTRandom();

		void Init(int seed) override;
		int GenRandom(int range) override;
		int Range(int minValue, int maxValue) override;
	};

}
