#include "TextureAsset.h"
#include "../Utils/Log.h"

namespace Graphics
{

	TextureAsset::TextureAsset(): m_texture{ std::make_unique<sf::Texture>() }
	{
	}

	void TextureAsset::Load()
	{
		auto log = Utils::Log::Get("TextureAsset");

		auto result = m_texture->loadFromFile(Path);
		if (!result)
		{
			log->error("Failed to load TextureAsset {0}", Path);
			InError = true;
			return;
		}
		m_texture->setSmooth(true);			

		log->info("Loaded {0}", Path);
	}

	void TextureAsset::Unload()
	{
	}

	void* TextureAsset::Get()
	{
		if (m_texture == nullptr)
		{
			auto log = Utils::Log::Get("TextureAsset");
			log->error() << "Get called before asset loaded for " << Path;
		}
		return (void*) m_texture.get();
	}

	TextureAsset::~TextureAsset()
	{
	}

}