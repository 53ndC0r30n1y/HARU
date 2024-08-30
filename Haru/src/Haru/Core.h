#pragma once
#ifdef HARU_PLATFORM_WINDOWS
#if HARU_DYNAMIC_LINK
#ifdef HARU_BUILD_DLL
#define HARU_API __declspec(dllexport)
#else
#define HARU_API __declspec(dllimport)
#endif
#else
#define HARU_API
#endif
#else
#error Haru only support Windows!
#endif

#ifdef HARU_ENABLE_ASSERTS
#define HARU_ASSERT(x, ...)                             \
  {                                                     \
    if (!(x)) {                                         \
      HARU_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
      __debugbreak();                                   \
    }                                                   \
  }
#define HARU_CORE_ASSERT(x, ...)                             \
  {                                                          \
    if (!(x)) {                                              \
      HARU_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
      __debugbreak();                                        \
    }                                                        \
  }
#else
#define HARU_ASSERT(x, ...)
#define HARU_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)