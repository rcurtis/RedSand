#include "SpriteAnimationAsset.h"
#include "../Utils/Log.h"

namespace Graphics
{

	SpriteAnimationAsset::SpriteAnimationAsset(const std::string& path)
		: path{ path }, texture{ std::make_unique<sf::Texture>() }
	{
	}

	SpriteAnimationAsset::~SpriteAnimationAsset()
	{
	}

	bool SpriteAnimationAsset::Load()
	{
		auto log = Utils::Log::Get("SpriteAnimationAsset");

		auto inError = false;
		atlas.Load(path);
		auto dot = path.find_last_of('.');
		auto texturePath = path.substr(0, dot) + ".png";
		texture->loadFromFile(texturePath);
		if (!texture)
		{
			log->error("Failed to load SpriteAnimationAsset {0}", path);
			inError = true;
			return inError;
		}
		texture->setSmooth(true);

		log->info("Loaded {0}", path);
		return inError;
	}

	void SpriteAnimationAsset::Unload()
	{
		if(texture)
			texture.release();
	}

	std::unique_ptr<S2D::SpriteAnimation> SpriteAnimationAsset::GetSpriteAnimation()
	{
		auto anim = std::make_unique<S2D::SpriteAnimation>();
		anim->SetAtlas(&atlas);
		anim->SetTexture(texture.get());
		return std::move(anim);
	}
}
