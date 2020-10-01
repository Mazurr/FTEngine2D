#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace FTE {
	class FTE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define FTE_CORE_TRACE(...)    ::FTE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FTE_CORE_INFO(...)     ::FTE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FTE_CORE_WARN(...)     ::FTE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FTE_CORE_ERROR(...)    ::FTE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FTE_CORE_CRITICAL(...) ::FTE::Log::GetCoreLogger()->critical(__VA_ARGS__)
								 
// Client log macros			 
#define FTE_TRACE(...)         ::FTE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FTE_INFO(...)          ::FTE::Log::GetClientLogger()->info(__VA_ARGS__)
#define FTE_WARN(...)          ::FTE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FTE_ERROR(...)         ::FTE::Log::GetClientLogger()->error(__VA_ARGS__)
#define FTE_CRITICAL(...)      ::FTE::Log::GetClientLogger()->critical(__VA_ARGS__)