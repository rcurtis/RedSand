#pragma once

#include "../Graphics/Stage.h"
#include "../Graphics/WindowDescription.h"

namespace Games
{

	class DummyGame : public Graphics::Stage
	{
	public:
		void Update(float delta, std::string tag) override;
		void Draw(float delta, std::string tag) override;
		DummyGame();
		~DummyGame() override;
	};

}