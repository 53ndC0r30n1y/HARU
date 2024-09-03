/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 14:30
 @file    : XenApp.cpp
 @brief   :
----------------------------------------------------------------------------
                           Change History
----------------------------------------------------------------------------
v0.1  : simple test
===========================================================================
*/

#include "Haru.h"
#include "imgui.h"

class ExampleLayer : public Haru::Layer {
public:
  ExampleLayer(): Layer("Example") { }

  void OnUpdate() override {
    if (Haru::Input::IsKeyPressed(HARU_KEY_TAB)) HARU_TRACE("Tab key is pressed (poll)!");
  }

  virtual void OnImGuiRender() override {
    ImGui::Begin("Test");
    ImGui::Text("Hello World");
    ImGui::End();
  }
  void OnEvent(Haru::Event &event) override {
    if (event.GetEventType() == Haru::EventType::KeyPressed) {
      Haru::KeyPressedEvent &e = (Haru::KeyPressedEvent &)event;
      if (e.GetKeyCode() == HARU_KEY_TAB) HARU_TRACE("Tab key is pressed (event)!");
      HARU_TRACE("{0}", (char)e.GetKeyCode());
    }
  }
};

class SandBox : public Haru::Application {
public:
  SandBox() {
    PushLayer(new ExampleLayer());
  }

  ~SandBox() { }
};

Haru::Application *Haru::CreateApplication() { return new SandBox(); }