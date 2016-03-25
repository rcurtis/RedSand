#pragma once

namespace Cruncher
{
	class IRandom
	{
	public:
		virtual ~IRandom() = default;

		virtual void Init(int seed) = 0;
		virtual int GenRandom(int range) = 0;
		virtual int Range(int minValue, int maxValue) = 0;
	};
}