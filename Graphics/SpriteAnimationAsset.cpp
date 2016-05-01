#include "SpriteAnimationAsset.h"

namespace Graphics
{

	SpriteAnimationAsset::SpriteAnimationAsset()
	{
	}

	SpriteAnimationAsset::~SpriteAnimationAsset()
	{
		if (texture)
		{
			delete texture;
			texture = nullptr;
		}
	}

	void SpriteAnimationAsset::Load()
	{
		atlas.Load(Path);
		auto dot = Path.find_last_of('.');
		auto texturePath = Path.substr(0, dot) + ".png";
		texture = new sf::Texture();
		texture->loadFromFile(texturePath);
		animation.SetAtlas(&atlas);
		animation.SetTexture(texture);
	}

	void SpriteAnimationAsset::Unload()
	{
		if (texture)
		{
			delete texture;
			texture = nullptr;
		}
	}

	void* SpriteAnimationAsset::Get()
	{
		return &animation;
	}
}
