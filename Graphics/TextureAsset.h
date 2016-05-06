#pragma once
#include "Asset.h"
#include "../Utils/NonCopyable.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace Graphics
{

	class TextureAsset : Utils::NonCopyable
	{
	public:	
		TextureAsset(const std::string& path);
		~TextureAsset();

		bool Load();
		void Unload();
		sf::Texture* GetTexture();

	private:
		const std::string Path;
		std::unique_ptr<sf::Texture> texture;
	};

}
