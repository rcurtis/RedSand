#include "TexturePackerAtlas.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <rapidjson/document.h>
#include "../Utils/Log.h"

using namespace rapidjson;

namespace Graphics
{

	static std::string ReadFileToString(const std::string& fileName)
	{
		std::ifstream in(fileName);
		if (!in.is_open())
		{
			auto log = Utils::Log::Get("TexturePackerAtlas");
			log->error("Could not find atlas file: {0}", fileName);
		}
		std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		return contents;
	}

	bool TexturePackerAtlas::Load(const std::string& fileName)
	{
		auto jsonString = ReadFileToString(fileName);

		Document doc;
		if (doc.Parse(jsonString.c_str()).HasParseError())
		{
			std::cout << "Error decoding json" << std::endl;
		}
		assert(doc.IsObject());

		const auto& frames = doc["frames"];
		assert(frames.IsArray());

		for (SizeType i = 0; i < frames.Size(); i++)
		{
			auto frame = std::make_shared<Frame>();
			frame->filename = frames[i]["filename"].GetString();

			frame->frame.x = frames[i]["frame"]["x"].GetInt();
			frame->frame.y = frames[i]["frame"]["y"].GetInt();
			frame->frame.w = frames[i]["frame"]["w"].GetInt();
			frame->frame.h = frames[i]["frame"]["h"].GetInt();

			frame->rotated = frames[i]["rotated"].GetBool();
			frame->trimmed = frames[i]["trimmed"].GetBool();

			frame->spriteSourceSize.x = frames[i]["spriteSourceSize"]["x"].GetInt();
			frame->spriteSourceSize.y = frames[i]["spriteSourceSize"]["y"].GetInt();
			frame->spriteSourceSize.w = frames[i]["spriteSourceSize"]["w"].GetInt();
			frame->spriteSourceSize.h = frames[i]["spriteSourceSize"]["h"].GetInt();

			frame->pivot.x = frames[i]["pivot"]["x"].GetFloat();
			frame->pivot.y = frames[i]["pivot"]["y"].GetFloat();

			_atlas->frames.push_back(frame);
		}

		std::sort(_atlas->frames.begin(), _atlas->frames.end(), [](std::shared_ptr<Frame> left, std::shared_ptr<Frame> right)
		{
			return left->filename < right->filename;
		});

		const auto& meta = doc["meta"];
		assert(meta.IsObject());

		_atlas->meta.app = meta["app"].GetString();
		_atlas->meta.version = meta["version"].GetString();
		_atlas->meta.image = meta["image"].GetString();
		_atlas->meta.format = meta["format"].GetString();
		_atlas->meta.size.x = meta["size"]["w"].GetFloat();
		_atlas->meta.size.y = meta["size"]["w"].GetFloat();

		// Weird edge case that can't parse directly to a float for some reason
		auto scale = meta["scale"].GetString();
		_atlas->meta.scale = std::stof(scale);

		_atlas->meta.smartupdate = meta["smartupdate"].GetString();
		return true;
	}

	TexturePackerAtlas::~TexturePackerAtlas()
	{
	}

}