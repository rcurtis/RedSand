#include "MainScreen.h"
#include "../Graphics/AssetManager.h"

namespace Games
{

	MainScreen::MainScreen()
	{
		button = std::make_shared<S2D::Button>(
			"../TestAssets/Play_00.png",
			"../TestAssets/Play_01.png",
			"../TestAssets/Misc1.png"
			);
		button->tag = "button";

		auto log = Utils::Log::Get("MainScreen");

		button->SetClickListener([this, log](auto& tag)
		{
			log->info("Button Clicked!");
			if (this->sevenAnim->IsPlaying())
				this->sevenAnim->Stop();
			else
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
		manager.Load("../TestAssets/Play_00.png", "button");
		manager.Load("../TestAssets/symbolSeven.spriteatlas", "symbolSeven");
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
