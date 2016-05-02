#include "MainScreen.h"
#include "../Graphics/AssetManager.h"

namespace Games
{

	MainScreen::MainScreen()
	{
		button = std::make_shared<S2D::Button>(
			"D:/gamewarrior/Assets/Graphics/SlotVideo/5Reel/Common/Buttons/Play1.png",
			"D:/gamewarrior/Assets/Graphics/SlotVideo/5Reel/Common/Buttons/Play_01.png",
			"D:/gamewarrior/Assets/Graphics/SlotVideo/5Reel/Common/Buttons/Misc1.png"
			);
		button->tag = "button";

		auto log = Utils::Log::Get("MainScreen");

		button->SetClickListener([this, log](auto& tag)
		{
			log->info("Button Clicked!");
			this->sevenAnim->Play();
		});
		AddChild(button);
	}

	MainScreen::~MainScreen()
	{
	}

	void MainScreen::OnUpdate(float delta)
	{
	}

	void MainScreen::OnLoad()
	{
		auto& manager = Graphics::AssetManager::instance();
		manager.Load("D:/gamewarrior/Assets/Graphics/SlotVideo/5Reel/Common/Buttons/Play1.png", "button");
		manager.Load("C:/Users/Robert/Desktop/RedSand/TestAssets/symbolSeven.spriteatlas", "symbolSeven");
	}

	void MainScreen::OnLoadComplete()
	{
		auto& manager = Graphics::AssetManager::instance();
		auto texture = manager.GetAsset<sf::Texture>("button");
		image = std::make_shared<Graphics::Image>(texture);
		image->setPosition(300.f, 300.f);
		AddChild(image);

		sevenAnim = std::shared_ptr<S2D::SpriteAnimation>(manager.GetAsset<S2D::SpriteAnimation>("symbolSeven"));
		sevenAnim->setPosition(300, 0);
		sevenAnim->SetFramesPerSecond(30);
		AddChild(sevenAnim);
	}
}
