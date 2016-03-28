#include "Stage.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../Utils/Log.h"
#include <memory>
#include "FrameRate.h"

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
		auto log = Utils::Log::Get("RunLoop");
		log->info() << "Starting main game loop";

		sf::Clock clock;
		// Probably a poor name for this.  It actually tracks the framerate, it does not SET it.
		FrameRate framerate(60);

		while (m_running)
		{
			if (!m_windowDescriptions.empty())
			{
				for (auto& desc : m_windowDescriptions)
				{
					auto window = new sf::RenderWindow{ sf::VideoMode{ unsigned int(desc.width), unsigned int(desc.height) }, desc.name };
					window->setPosition(sf::Vector2i{ desc.x, desc.y });
					m_windows.insert({ desc.tag, window });
				}
				m_windowDescriptions.clear();
			}

			for (auto& pair : m_windows)
			{
				auto window = pair.second;
				auto tag = pair.first;

				sf::Event evnt;
				while (window->pollEvent(evnt))
				{
					if (evnt.type == sf::Event::Closed)
					{
						log->info() << "Window closed with tag: " << pair.first;
						window->close();
						m_windows.erase(m_windows.find(pair.first));
						delete window;
						m_running = false;
						break;
					}
				}

				// We could have just processed a window close event. 
				// TODO: cleaner shutdown, unload assets and notify the platform.
				if (!m_running)
				{
					break;
				}

				window->clear(sf::Color{255, 0, 255});

				auto delta = clock.getElapsedTime().asSeconds();
				clock.restart();
				framerate.AddDataPoint(delta);

				// Virtual calls to game classes that inherit... AKA all of the games.
				Update(delta, tag);
				Draw(delta, tag);

				window->display();
			}
			Sleep(1);
		}
		log->info() << "Exiting main game loop";
	}

	Stage::~Stage()
	{
		for (auto& pair : m_windows)
		{
			auto window = pair.second;
			window->close();
			delete window;
		}
		m_windows.clear();
	}

}