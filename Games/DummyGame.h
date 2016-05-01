#pragma once

#include "../Graphics/Stage.h"
#include "../Graphics/WindowDescription.h"
#include "TopScreen.h"
#include "MainScreen.h"

namespace Games
{

	class DummyGame : public Graphics::Stage
	{
	public:
		void Load() override;
		void LoadComplete() override;
		void Update(float delta, std::string tag) override;
		void Draw(const std::string& tag, sf::RenderWindow* window) override;
		
		void MousePressed(int buttonCode, int x, int y) override;
		void MouseReleased(int buttonCode, int x, int y) override;
		void MouseMoved(const std::string& windowTag, int x, int y) override;

		DummyGame();
		~DummyGame() override;

	private:
		std::shared_ptr<TopScreen> m_topRoot;
		std::shared_ptr<MainScreen> m_mainRoot;
	};

}
