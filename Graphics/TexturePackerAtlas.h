#pragma once
#include <memory>
#include <vector>
#include <string>
#include "../Utils/NonCopyable.h"

namespace Graphics
{

	class TexturePackerAtlas : public Utils::NonCopyable
	{
		struct Point
		{
			float x, y;
		};

		struct Rect
		{
			int x, y, w, h;
		};

		struct Frame
		{
			std::string filename;
			Rect frame;
			bool rotated;
			bool trimmed;
			Rect spriteSourceSize;
			Point pivot;
		};

		struct Meta
		{
			std::string app;
			std::string version;
			std::string image;
			std::string format;
			Point size;
			float scale;
			std::string smartupdate;
		};

		struct Atlas
		{
			std::vector<std::shared_ptr<Frame>> frames;
			Meta meta;
		};

	private:
		std::shared_ptr<Atlas> _atlas;

	public:
		TexturePackerAtlas() 
			: _atlas(std::make_shared<Atlas>())
		{			
		}
		bool Load(const std::string& fileName);
		~TexturePackerAtlas();

		const std::shared_ptr<Atlas>& atlas() const
		{
			return _atlas;
		}
	};

}