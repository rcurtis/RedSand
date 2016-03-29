#pragma once
#include "Asset.h"
#include "SFML/Graphics.hpp"

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
		sf::Texture* m_texture;
	};

}
