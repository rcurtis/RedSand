#pragma once

#include <string>
#include "Asset.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Utils/Log.h"
#include "Image.h"
#include "SpriteAnimation.h"

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

		std::unique_ptr<Image> GetImage(const std::string& tag);
		std::unique_ptr<S2D::SpriteAnimation> GetSpriteAnimation(const std::string& tag);

	protected:
		void Unload();
		void DoLoad();
	private:
		AssetManager()
		{
		}
		std::vector<std::unique_ptr<Asset>> m_assets;
		Asset::AssetType DeduceType(const std::string& path);

	};	

}
