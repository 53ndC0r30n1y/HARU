/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : Log.h
 @brief   :
===========================================================================
*/

#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include "Harupch.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Haru {
/***********************************************************************

  Log

***********************************************************************/

class HARU_API Log {
public:
  Log();
  ~Log();

  static void Init();

  inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
    return s_CoreLogger;
  }
  inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
    return s_ClientLogger;
  }

private:
  static std::shared_ptr<spdlog::logger> s_CoreLogger;
  static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
} // namespace Haru

// Core Log Macros
#define HARU_CORE_TRACE(...) ::Haru::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HARU_CORE_INFO(...) ::Haru::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HARU_CORE_WARN(...) ::Haru::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HARU_CORE_ERROR(...) ::Haru::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HARU_CORE_FATAL(...) ::Haru::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define HARU_TRACE(...) ::Haru::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HARU_INFO(...) ::Haru::Log::GetClientLogger()->info(__VA_ARGS__)
#define HARU_WARN(...) ::Haru::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HARU_ERROR(...) ::Haru::Log::GetClientLogger()->error(__VA_ARGS__)
#define HARU_FATAL(...) ::Haru::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif // !LOG_H
