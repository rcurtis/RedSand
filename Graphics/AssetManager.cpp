#include "AssetManager.h"
#include <algorithm>
#include <SFML/Graphics/Texture.hpp>
#include "../Utils/Log.h"
#include "TextureAsset.h"

namespace Graphics
{

	void AssetManager::Load(const std::string& path, const std::string& tag)
	{
		auto find = std::find_if(m_assets.begin(), m_assets.end(), [&path](std::shared_ptr<Asset> asset)
		{
			return asset->Path == path;
		});
		if (find != m_assets.end())
		{
			(*find)->Tags.insert(tag);
			return;
		}

		auto type = DeduceType(path);
		switch (type)
		{
		case Loadables::Texture:
			auto asset = std::make_shared<TextureAsset>();
			asset->LoadableType = type;
			asset->Path = path;
			asset->Tags.insert(tag);
			m_assets.push_back(asset);
		}
	}

	sf::Texture* AssetManager::GetTexture(const std::string& tag)
	{
		auto find = std::find_if(m_assets.begin(), m_assets.end(), [&tag](std::shared_ptr<Asset> asset)
		{
			return asset->Tags.count(tag) > 0;
		});
		if (find == m_assets.end())
		{
			auto log = Utils::Log::Get("GetTexture");
			log->error() << "Tag '" << tag << "' requested but not found in AssetManager";
		}

		auto asset = *find;
		auto retval = static_cast<sf::Texture*>(asset->Get());
		return retval;
	}

	void AssetManager::Unload()
	{
		for (auto& asset : m_assets)
		{
			asset->Unload();			
		}
		m_assets.clear();
	}

	void AssetManager::DoLoad()
	{
		for (auto& asset : m_assets)
		{
			asset->Load();
		}
	}

	Loadables AssetManager::DeduceType(const std::string& path)
	{
		std::string extention = path.substr(path.size() - 3);

		if (extention == "png")
		{
			return Loadables::Texture;
		}
	}
}
