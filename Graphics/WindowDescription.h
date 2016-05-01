#pragma once

#include <string>

namespace Graphics
{

	class WindowDescription
	{
	public:
		WindowDescription(){}
		~WindowDescription(){}

		std::string tag;
		std::string name;
		int x;
		int y;
		int width;
		int height;
		bool showBorder;
	};

}