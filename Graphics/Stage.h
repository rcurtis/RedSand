#pragma once

#include "WindowDescription.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <thread>
#include <string>
#include <memory>
#include "Actor.h"

namespace Graphics
{

	class Stage
	{
	public:
		Stage();
		virtual ~Stage();

		void CloseWindows();
		void Run();
		void Shutdown();

		virtual void Update(float delta, std::string tag) = 0;
		virtual void Draw(std::string tag, sf::RenderWindow* window) = 0;
		virtual void Load() = 0;
		virtual void LoadComplete() = 0;

	protected:
		void AddWindow(WindowDescription description);
		void RegisterRootActor(std::string tag, std::shared_ptr<Actor> actor);

		float m_fps;

	private:
		void RunLoop();
		bool m_running;
		std::thread m_runLoop;
		bool m_loadComplete;
		std::vector<WindowDescription> m_windowDescriptions;
		std::map<std::string, sf::RenderWindow*> m_windows;
	};

}
