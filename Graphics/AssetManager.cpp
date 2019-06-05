#include "AssetManager.h"
#include <algorithm>
#include <SFML/Graphics/Texture.hpp>
#include "../Utils/Log.h"
#include "TextureAsset.h"
#include "SpriteAnimationAsset.h"

namespace Graphics
{

	void AssetManager::Load(const std::string& path, const std::string& tag)
	{
		auto find = std::find_if(m_assets.begin(), m_assets.end(), [&path](auto& asset)
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
		case Asset::AssetType::Image:
		{
			auto asset = std::make_unique<Asset>();
			if(asset->textureAsset)
			{
				auto i = 0;
			}
			asset->textureAsset = std::make_unique<TextureAsset>(path);
			asset->Type = type;
			asset->Path = path;
			asset->Tags.insert(tag);
			m_assets.push_back(std::move(asset));
			break;
		}
			
		case Asset::AssetType::SpriteAnimation:
		{
			auto asset = std::make_unique<Asset>();
			asset->spriteAnimationAsset = std::make_unique<SpriteAnimationAsset>(path);
			asset->Type = type;
			asset->Path = path;
			asset->Tags.insert(tag);
			m_assets.push_back(std::move(asset));
			break;
		}
		case Asset::AssetType::Error: break;
		default: break;
		}
	}

	std::unique_ptr<Image> AssetManager::GetImage(const std::string& tag)
	{
		auto find = std::find_if(m_assets.begin(), m_assets.end(), [&tag](auto& asset)
		{
			return asset->Tags.count(tag) > 0;
		});
		if (find == m_assets.end())
		{
			auto log = Utils::Log::Get("GetImage");
			log->error() << "Tag '" << tag << "' requested but not found in AssetManager";
		}

		auto asset = find->get();
		auto texture = asset->textureAsset->GetTexture();
		auto image = std::make_unique<Image>(texture);
		return std::move(image);
	}

	std::unique_ptr<S2D::SpriteAnimation> AssetManager::GetSpriteAnimation(const std::string& tag)
	{
		auto find = std::find_if(m_assets.begin(), m_assets.end(), [&tag](auto& asset)
		{
			return asset->Tags.count(tag) > 0;
		});
		if (find == m_assets.end())
		{
			auto log = Utils::Log::Get("GetImage");
			log->error() << "Tag '" << tag << "' requested but not found in AssetManager";
		}

		auto asset = find->get();
		auto animation = asset->spriteAnimationAsset->GetSpriteAnimation();
		return std::move(animation);
	}

	void AssetManager::Unload()
	{
		for (auto& asset : m_assets)
		{
			switch (asset->Type)
			{
			case Asset::AssetType::Image:
			{
				asset->textureAsset->Unload();
				break;
			};
			case Asset::AssetType::SpriteAnimation: 
			{
				asset->spriteAnimationAsset->Unload();
				break;
			};
			default: break;
			}		
		}
		m_assets.clear();
	}

	void AssetManager::DoLoad()
	{
		for (auto& asset : m_assets)
		{
			switch (asset->Type)
			{
			case Asset::AssetType::Image:
			{
				asset->InError = asset->textureAsset->Load();
				break;
			}
			case Asset::AssetType::SpriteAnimation:
			{
				asset->InError = asset->spriteAnimationAsset->Load();
				break;
			}
			default: break;
			}
		}
	}

	Asset::AssetType AssetManager::DeduceType(const std::string& path)
	{
		auto dot = path.find_last_of('.');
		auto extention = path.substr(dot);

		if (extention == ".png")
		{
			return Asset::AssetType::Image;
		}
		if(extention == ".spriteatlas")
		{
			return Asset::AssetType::SpriteAnimation;
		}
		return Asset::AssetType::Error;
	}
}
