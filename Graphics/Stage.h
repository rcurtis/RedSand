#pragma once
#pragma once

#include "WindowDescription.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <thread>

namespace Graphics
{

	class Stage
	{
	public:
		Stage();
		~Stage();

		void AddWindow(WindowDescription description);
		void CloseWindows();
		void Run();
		void Shutdown();

	private:
		void RunLoop();
		bool m_running;
		std::thread m_runLoop;
		std::vector<WindowDescription> m_windowDescriptions;
		std::vector<sf::RenderWindow*> m_windows;
	};

}