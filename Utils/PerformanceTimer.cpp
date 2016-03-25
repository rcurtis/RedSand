#include "PerformanceTimer.h"


Utils::PerformanceTimer::PerformanceTimer(const std::string& message)
	:_message(std::move(message)),
	_start(std::chrono::high_resolution_clock::now()),
	_didExpire(false)
{
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
	//LOG_INFO << _message << " -- " << elapsedMiliseconds.count() << " m/s.";
	_didExpire = true;
}
