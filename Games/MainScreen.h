#pragma once
#include "../Graphics/Actor.h"
#include "../Graphics/Image.h"
#include "../Graphics/Button.h"
#include "../Graphics/SpriteAnimation.h"

namespace Games
{

	class MainScreen : public Graphics::Actor
	{
	public:
		MainScreen();
		virtual ~MainScreen();

	protected:
		void OnUpdate(float delta) override;
		void OnLoad() override;
		void OnLoadComplete() override;

		std::shared_ptr<Graphics::Image> image;
		std::shared_ptr<S2D::Button> button;
		std::shared_ptr<S2D::SpriteAnimation> sevenAnim;
	};

}
