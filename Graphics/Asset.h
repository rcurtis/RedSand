#pragma once

#include <set>
#include "Loadables.h"

namespace Graphics
{

	class Asset
	{
	public:
		Asset();
		virtual ~Asset();

		std::string Path;
		std::set<std::string> Tags;
		Loadables LoadableType;
		bool InError;

		virtual void Load() = 0;
		virtual void Unload() = 0;
		virtual void* Get() = 0;
	};

}
