#pragma once
#include "../Graphics/Actor.h"
#include "../Graphics/Image.h"

namespace Games
{

	class TopScreen : public Graphics::Actor
	{
	public:
		TopScreen();
		virtual ~TopScreen();

		void LoadComplete() override;

	protected:
		void OnUpdate(float delta) override;
		void OnLoad() override;

	private:
		std::shared_ptr<Graphics::Image> m_img;
	};

}
