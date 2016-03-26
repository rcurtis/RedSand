#include "OutputDebugStringSink.h"
#include <Windows.h>

namespace Utils
{

	OutputDebugStringSink::OutputDebugStringSink()
	{
	}

	OutputDebugStringSink::~OutputDebugStringSink()
	{
	}

	void OutputDebugStringSink::flush()
	{
	}

	void OutputDebugStringSink::_sink_it(const spdlog::details::log_msg& msg)
	{
		OutputDebugString(msg.formatted.c_str());
	}
}
