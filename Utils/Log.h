#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/logger.h"
#include "spdlog/common.h"
#include <vector>
#include <memory>
#include <map>

namespace Utils
{
	class Log
	{
	public:
		Log() {	}
		~Log() = default;

		static void Init(const std::string& outputFile);
		static std::shared_ptr<spdlog::logger> Get(const std::string& loggerName);

	private:
		static std::vector<spdlog::sink_ptr> sinks;
		static std::map <std::string, std::shared_ptr<spdlog::logger>> _loggers;
		static bool initialized;

		static std::shared_ptr<spdlog::logger> MakeLogger(const std::string& loggerName);
	};	
}