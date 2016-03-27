#include "Stage.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

namespace Graphics
{

	Stage::Stage()
	{
	}

	void Stage::AddWindow(WindowDescription description)
	{
		m_windowDescriptions.push_back(description);
	}

	void Stage::CloseWindows()
	{
	}

	void Stage::Run()
	{
		m_running = true;
		m_runLoop = std::thread(&Stage::RunLoop, this);
		m_runLoop.detach();
	}

	void Stage::Shutdown()
	{
		m_running = false;
	}

	void Stage::RunLoop()
	{
		while (m_running)
		{
			if (!m_windowDescriptions.empty())
			{
				for (const auto& desc : m_windowDescriptions)
				{
					auto window = new sf::RenderWindow{ sf::VideoMode{ unsigned int(desc.width), unsigned int(desc.height) }, desc.name };
					window->setPosition(sf::Vector2i{ desc.x, desc.y });
					m_windows.push_back(window);
				}
				m_windowDescriptions.clear();
			}

			for (const auto& window : m_windows)
			{
				sf::Event evnt;
				while (window->pollEvent(evnt))
				{
					if (evnt.type == sf::Event::Closed)
						window->close();
				}
				window->clear(sf::Color{255, 0, 255});
				window->display();
			}
			Sleep(1);
		}
		
	}

	Stage::~Stage()
	{
		for (const auto& window : m_windows)
		{
			window->close();
			delete window;
		}
		m_windows.clear();
	}

}