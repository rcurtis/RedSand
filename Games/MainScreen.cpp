#include "MainScreen.h"
#include "../Graphics/AssetManager.h"

namespace Games
{

	MainScreen::MainScreen()
	{
	}

	MainScreen::~MainScreen()
	{
	}

	void MainScreen::LoadComplete()
	{
		auto& manager = Graphics::AssetManager::instance();
		auto texture = manager.GetAsset<sf::Texture>("button");
		button = std::make_shared<Graphics::Image>(texture);
		button->setPosition(300.f, 300.f);
		AddChild(button);
	}

	void MainScreen::OnUpdate(float delta)
	{
	}

	void MainScreen::OnLoad()
	{
		auto& manager = Graphics::AssetManager::instance();
		manager.Load("D:/gamewarrior/Assets/Graphics/SlotVideo/5Reel/Common/Buttons/Play1.png", "button");
	}

}
