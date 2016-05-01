#pragma once

#include <string>
#include "Asset.h"
#include <vector>
#include <memory>
#include "Loadables.h"
#include <SFML/Graphics.hpp>
#include "../Utils/Log.h"

namespace Graphics
{
	enum class Loadables;

	class AssetManager
	{
	public:
		friend class Stage;

		static AssetManager& instance()
		{
			static AssetManager instance;
			return instance;
		}
		AssetManager(AssetManager const&) = delete;
		void operator=(AssetManager const&) = delete;

		void Load(const std::string& path, const std::string& tag);

		//sf::Texture* GetTexture(const std::string& tag);

		template<class T>
		T* GetAsset(const std::string& tag)
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
			auto retval = static_cast<T*>(asset->Get());
			return retval;
		}

	protected:
		void Unload();
		void DoLoad();
	private:
		AssetManager()
		{
		};
		std::vector<std::shared_ptr<Asset>> m_assets;
		Loadables DeduceType(const std::string& path);

	};	

}
