#pragma once
#include "Asset.h"
#include "../Utils/NonCopyable.h"
#include "TexturePackerAtlas.h"
#include <SFML/Graphics/Texture.hpp>
#include "SpriteAnimation.h"

namespace Graphics
{

	class SpriteAnimationAsset : Utils::NonCopyable
	{
	public:
		SpriteAnimationAsset(const std::string& path);
		~SpriteAnimationAsset();

		bool Load();
		void Unload();
		std::unique_ptr<S2D::SpriteAnimation> GetSpriteAnimation();

	private:
		const std::string path;

		Graphics::TexturePackerAtlas atlas;
		std::unique_ptr<sf::Texture> texture;
		S2D::SpriteAnimation animation;
	};

}
