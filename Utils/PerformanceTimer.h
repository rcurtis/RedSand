#pragma once

#include <chrono>
#include <string>
#include "Log.h"

namespace Utils
{

	class PerformanceTimer
	{
	public:
		PerformanceTimer(const std::string& message);
		~PerformanceTimer();
		void Expire();

	private:
		static std::shared_ptr<spdlog::logger> _logger;
		const std::string _message;
		std::chrono::time_point<std::chrono::steady_clock> _start;
		bool _didExpire;
	};


}