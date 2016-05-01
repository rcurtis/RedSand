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

	protected:
		void OnUpdate(float delta) override;
		void OnLoad() override;
		void OnLoadComplete() override;

	private:
		std::shared_ptr<Graphics::Image> m_img;
	};

}
