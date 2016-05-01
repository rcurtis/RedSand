#include "TextureAsset.h"
#include "../Utils/Log.h"

namespace Graphics
{

	TextureAsset::TextureAsset(): m_texture(nullptr)
	{
	}

	void TextureAsset::Load()
	{
		auto log = Utils::Log::Get("TextureAsset");

		m_texture = new sf::Texture();
		try
		{
			auto result = m_texture->loadFromFile(Path);
			if (!result)
			{
				log->error("Failed to load TextureAsset {0}", Path);
				return;
			}
			m_texture->setSmooth(true);
		}
		catch (...)
		{
			
			InError = true;
			log->error() << "Failed to load asset: " << Path;
		}

		log->info() << "Loaded : " << Path;
	}

	void TextureAsset::Unload()
	{
		if (m_texture)
			delete m_texture;
	}

	void* TextureAsset::Get()
	{
		if (m_texture == nullptr)
		{
			auto log = Utils::Log::Get("TextureAsset");
			log->error() << "Get called before asset loaded for " << Path;
		}
		return (void*) m_texture;
	}

	TextureAsset::~TextureAsset()
	{
	}

}