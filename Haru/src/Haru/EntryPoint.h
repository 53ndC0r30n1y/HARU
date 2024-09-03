/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : EntryPoint.h
 @brief   :
===========================================================================
*/

#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
/***********************************************************************

  Windows Platform

***********************************************************************/

#ifdef HARU_PLATFORM_WINDOWS

extern Haru::Application *Haru::CreateApplication();

int main(int argc, char **argv) {
  Haru::Log::Init();

  // General style
  Haru::Log::GetCoreLogger()->warn("原始代码输出日志");
  Haru::Log::GetClientLogger()->error("原始代码输出日志");

  // use macro
  HARU_CORE_WARN("Initialized Log!");
  int a = 5;
  HARU_INFO("Hello! Var={0}", a);

  auto app = Haru::CreateApplication();
  app->Run();
  delete app;
}
#endif

#endif // !ENTRYPOINT_H
