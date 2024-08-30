#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef HARU_PLATFORM_WINDOWS

extern Haru::Application* Haru::CreateApplication();

int main(int argc, char** argv) {
  Haru::Log::Init();

  // ԭ�����������־
  Haru::Log::GetCoreLogger()->warn("ԭʼ���������־");
  Haru::Log::GetClientLogger()->error("ԭʼ���������־");

  // �ú궨�壬�����־
  HARU_CORE_WARN("Initialized Log!");
  int a = 5;
  HARU_INFO("Hello! Var={0}", a);

  auto app = Haru::CreateApplication();
  app->Run();
  delete app;
}
#endif

#endif  // !ENTRYPOINT_H
