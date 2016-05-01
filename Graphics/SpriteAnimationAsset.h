#pragma once
#include "Asset.h"
#include "TexturePackerAtlas.h"
#include <SFML/Graphics/Texture.hpp>
#include "SpriteAnimation.h"

namespace Graphics
{

	class SpriteAnimationAsset : public Asset
	{
	public:
		SpriteAnimationAsset();
		~SpriteAnimationAsset();

		void Load() override;
		void Unload() override;
		void* Get() override;

	private:
		Graphics::TexturePackerAtlas atlas;
		sf::Texture* texture;
		S2D::SpriteAnimation animation;
	};

}
