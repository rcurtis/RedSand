#include "Log.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/file_sinks.h"

// static members
std::vector<spdlog::sink_ptr> Utils::Log::sinks;
std::map <std::string, std::shared_ptr<spdlog::logger>> Utils::Log::_loggers;
bool Utils::Log::initialized;

void Utils::Log::Init(const std::string& outputFile)
{
	try
	{
		sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
		sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(outputFile, "txt", 1024 * 1024, 10));
		auto combined_logger = std::make_shared<spdlog::logger>("log", std::begin(sinks), std::end(sinks));
		spdlog::register_logger(combined_logger);
		initialized = true;
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		std::cout << "Log failed: " << ex.what() << std::endl;
	}
}

std::shared_ptr<spdlog::logger> Utils::Log::Get(const std::string& loggerName)
{
	if (!initialized)
		throw "Must call initialize on Log before using it!";

	auto found = _loggers.begin();

	try
	{
		found = std::find_if(_loggers.begin(), _loggers.end(),
			[&loggerName](std::pair<std::string, std::shared_ptr<spdlog::logger>> pair)
		{
			return pair.first == loggerName;
		});
	}
	catch (const std::exception& ex)
	{
		MessageBox(nullptr, ex.what(), nullptr, 0);
	}

	//for ()

	if (found != _loggers.end())
	{
		return found->second;
	}

	auto logger = MakeLogger(loggerName);
	_loggers.insert({ loggerName, logger });
	return logger;
}

std::shared_ptr<spdlog::logger> Utils::Log::MakeLogger(const std::string& loggerName)
{
	return std::make_shared<spdlog::logger>(loggerName, std::begin(sinks), std::end(sinks));
}