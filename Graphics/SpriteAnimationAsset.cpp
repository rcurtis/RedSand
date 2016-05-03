#include "SpriteAnimationAsset.h"
#include "../Utils/Log.h"

namespace Graphics
{

	SpriteAnimationAsset::SpriteAnimationAsset()
		: texture{ std::make_unique<sf::Texture>() }
	{
	}

	SpriteAnimationAsset::~SpriteAnimationAsset()
	{
	}

	void SpriteAnimationAsset::Load()
	{
		auto log = Utils::Log::Get("SpriteAnimationAsset");

		atlas.Load(Path);
		auto dot = Path.find_last_of('.');
		auto texturePath = Path.substr(0, dot) + ".png";
		texture->loadFromFile(texturePath);
		if (!texture)
		{
			log->error("Failed to load SpriteAnimationAsset {0}", Path);
			InError = true;
			return;
		}
		texture->setSmooth(true);
		animation.SetAtlas(&atlas);
		animation.SetTexture(texture.get());

		log->info("Loaded {0}", Path);
	}

	void SpriteAnimationAsset::Unload()
	{
	}

	void* SpriteAnimationAsset::Get()
	{
		return &animation;
	}
}
