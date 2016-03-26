#include "PerformanceTimer.h"

std::shared_ptr<spdlog::logger> Utils::PerformanceTimer::_logger;

Utils::PerformanceTimer::PerformanceTimer(const std::string& message)
	:_message(std::move(message)),
	_start(std::chrono::high_resolution_clock::now()),
	_didExpire(false)
{
	static auto initialized = false;
	if (!initialized)
	{
		_logger = Log::Get("PerfTimer");
		initialized = true;
	}
}


Utils::PerformanceTimer::~PerformanceTimer()
{
	if (!_didExpire)
		Expire();
}

void Utils::PerformanceTimer::Expire()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto elapsed = now - _start;
	auto elapsedMiliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
	_logger->info() << _message << " -- " << elapsedMiliseconds.count() << " m/s.";
	_didExpire = true;
}
