#include "TopScreen.h"
#include "../Graphics/AssetManager.h"

namespace Games
{

	void TopScreen::OnUpdate(float delta)
	{
		auto log = Utils::Log::Get("Top");
		log->info("Top: {0}", delta);

		static float rotation = 0;
		static float scale = 0;
		rotation += delta * 200;
		scale += delta * 5;
		m_img->setRotation(rotation);
		m_img->setScale(abs(sin(scale)), abs(sin(scale)));
	}

	void TopScreen::OnLoad()
	{
		auto& manager = Graphics::AssetManager::instance();
		manager.Load("../TestAssets/bigredBG.png", "topscreenBG");
	}

	void TopScreen::OnLoadComplete()
	{
		auto& manager = Graphics::AssetManager::instance();
		auto img = manager.GetAsset<sf::Texture>("topscreenBG");
		m_img = std::make_shared<Graphics::Image>(img);
		m_img->setPosition(1024 / 2, 768 / 2);
		m_img->setOrigin(1024 / 2, 768 / 2);
		AddChild(m_img);
	}

	TopScreen::TopScreen()
	{
	}

	TopScreen::~TopScreen()
	{
	}

}