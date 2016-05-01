#pragma once
#include "../Graphics/Actor.h"
#include "../Graphics/Image.h"

namespace Games
{

	class MainScreen : public Graphics::Actor
	{
	public:
		MainScreen();
		virtual ~MainScreen();

		void LoadComplete() override;

	protected:
		void OnUpdate(float delta) override;
		void OnLoad() override;

		std::shared_ptr<Graphics::Image> button;
	};

}
