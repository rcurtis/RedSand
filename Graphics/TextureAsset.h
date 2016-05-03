#pragma once
#include "Asset.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace Graphics
{

	class TextureAsset : public Asset
	{
	public:	
		TextureAsset();
		~TextureAsset();

		void Load() override;
		void Unload() override;
		void* Get() override;

	private:
		std::unique_ptr<sf::Texture> m_texture;
	};

}
