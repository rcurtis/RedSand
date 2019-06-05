#include "PTRandom.h"
#include <stdlib.h>

namespace Cruncher
{

	PTRandom::PTRandom()
	{
	}

	PTRandom::~PTRandom()
	{
	}

	// TODO: Hook this into our RNG DLL.  This is for testing.
	void PTRandom::Init(int seed)
	{
		srand(seed);
	}

	// TODO: Hook this into our RNG DLL.  This is for testing.
	int PTRandom::GenRandom(int range)
	{
		return Range(0, range);
	}

	// TODO: Hook this into our RNG DLL.  This is for testing.
	int PTRandom::Range(int minValue, int maxValue)
	{
		return minValue + (rand() % static_cast<int>(maxValue - minValue + 1));
	}

}