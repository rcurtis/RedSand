#pragma once

#include <string>
#include "Asset.h"
#include <vector>
#include <memory>
#include "Loadables.h"
#include <SFML/Graphics.hpp>

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

		sf::Texture* GetTexture(const std::string& tag);

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
