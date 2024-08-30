#include "Haru.h"

class ExampleLayer : public Haru::Layer {
public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate() override { HARU_INFO("ExampleLayer::Update"); }

  void OnEvent(Haru::Event &event) override { HARU_TRACE("{0}", event.ToString()); }
};

class SandBox : public Haru::Application {
 public:
  SandBox() { PushLayer(new ExampleLayer());
  }

  ~SandBox() {}
};

Haru::Application* Haru::CreateApplication() { return new SandBox(); }