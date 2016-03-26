#pragma once

#include <spdlog/sinks/sink.h>
#include <spdlog/sinks/base_sink.h>

namespace Utils
{

	class OutputDebugStringSink : public spdlog::sinks::base_sink<std::mutex>
	{
	public:
		OutputDebugStringSink();
		~OutputDebugStringSink() override;

		// we dont actually do anything in flush, but it is required as a pure
		// virtual function from one of our base classes.
		void flush() override;

	protected:
		void _sink_it(const spdlog::details::log_msg& msg) override;
	};

}
