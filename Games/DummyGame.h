#pragma once

#include "../Graphics/Stage.h"
#include "../Graphics/WindowDescription.h"
#include "TopScreen.h"

namespace Games
{

	class DummyGame : public Graphics::Stage
	{
	public:
		void Load() override;
		void LoadComplete() override;
		void Update(float delta, std::string tag) override;
		void Draw(std::string tag, sf::RenderWindow* window) override;
		DummyGame();
		~DummyGame() override;

	private:
		std::shared_ptr<TopScreen> m_topRoot;
		std::shared_ptr<Graphics::Actor> m_mainRoot;
	};

}