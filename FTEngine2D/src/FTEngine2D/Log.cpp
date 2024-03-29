#include "ftepch.h"
#include "Log.h"

namespace FTE {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("FTEngine2D");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

		Log::GetCoreLogger()->set_level(spdlog::level::trace);
		Log::GetClientLogger()->set_level(spdlog::level::trace);
	}
}