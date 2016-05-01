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
		virtual void Draw(const std::string& tag, sf::RenderWindow* window) = 0;
		virtual void Load() = 0;
		virtual void LoadComplete() = 0;

		virtual void MousePressed(int buttonCode, int x, int y) = 0;
		virtual void MouseReleased(int buttonCode, int x, int y) = 0;
		virtual void MouseMoved(const std::string& windowTag, int x, int y) = 0;

	protected:
		void AddWindow(WindowDescription description);
		void RegisterRootActor(std::string tag, std::shared_ptr<Actor> actor);

		float m_fps;

	private:
		void DispatchMousePressed(int buttonCode, int x, int y);
		void DispatchMouseReleased(int button, int x, int y);
		void DispatchMouseMoved(const std::string& windowTag, int x, int y);
		void RunLoop();
		bool m_running;
		std::thread m_runLoop;
		bool m_loadComplete;
		std::vector<WindowDescription> m_windowDescriptions;
		std::map<std::string, sf::RenderWindow*> m_windows;
	};

}
