#include "TextureAsset.h"
#include "../Utils/Log.h"

namespace Graphics
{

	TextureAsset::TextureAsset(const std::string& path)
		: Path{ path }, texture{ std::make_unique<sf::Texture>() }
	{
	}

	bool TextureAsset::Load()
	{
		auto log = Utils::Log::Get("TextureAsset");

		auto inError = false;

		auto result = texture->loadFromFile(Path);
		if (!result)
		{
			log->error("Failed to load TextureAsset {0}", Path);
			inError = true;
			return inError;
		}
		texture->setSmooth(true);

		log->info("Loaded {0}", Path);
		return inError;
	}

	void TextureAsset::Unload()
	{
		if (texture)
			texture.release();
	}

	sf::Texture* TextureAsset::GetTexture()
	{
		if (texture == nullptr)
		{
			auto log = Utils::Log::Get("TextureAsset");
			log->error() << "Get called before asset loaded for " << Path;
		}
		return texture.get();
	}

	TextureAsset::~TextureAsset()
	{
		auto log = Utils::Log::Get("TextureAsset");
		log->warn("Destructor called");
	}

}