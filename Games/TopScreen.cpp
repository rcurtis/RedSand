#include "TopScreen.h"
#include "../Graphics/AssetManager.h"

namespace Games
{

	void TopScreen::OnUpdate(float delta)
	{
	}

	void TopScreen::OnLoad()
	{
		auto& manager = Graphics::AssetManager::instance();
		manager.Load("D:/gamewarrior/Assets/Graphics/SlotVideo/5Reel/20Line/BigRed/Background/Generic.png", "topscreenBG");

	}

	void TopScreen::LoadComplete()
	{
		auto& manager = Graphics::AssetManager::instance();
		auto img = manager.GetTexture("topscreenBG");
		m_img = std::make_shared<Graphics::Image>(img);
		AddChild(m_img);
	}

	TopScreen::TopScreen()
	{
	}


	TopScreen::~TopScreen()
	{
	}

}