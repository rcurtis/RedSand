#pragma once

#include "WindowDescription.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <thread>
#include <string>

namespace Graphics
{

	class Stage
	{
	public:
		Stage();
		virtual ~Stage();

		void AddWindow(WindowDescription description);
		void CloseWindows();
		void Run();
		void Shutdown();

		virtual void Update(float delta, std::string tag) = 0;
		virtual void Draw(float delta, std::string tag) = 0;

	protected:
		float m_fps;

	private:
		void RunLoop();
		bool m_running;
		std::thread m_runLoop;
		std::vector<WindowDescription> m_windowDescriptions;
		std::map<std::string, sf::RenderWindow*> m_windows;
	};

}