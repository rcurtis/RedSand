#pragma once

#include "../Utils/NonCopyable.h"
#include <set>
#include <memory>

namespace Graphics
{

	class TextureAsset;
	class SpriteAnimationAsset;

	class Asset : public Utils::NonCopyable
	{
	public:
		Asset(){}
		~Asset(){}

		enum class AssetType
		{
			Image,
			SpriteAnimation,
			Error
		};

		AssetType Type = AssetType::Error;
		std::string Path;
		std::set<std::string> Tags;
		bool InError = false;

		union
		{
			std::unique_ptr<TextureAsset> textureAsset;
			std::unique_ptr<SpriteAnimationAsset> spriteAnimationAsset;
		};
	};

}
