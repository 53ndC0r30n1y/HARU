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

class ExampleLayer : public Haru::Layer {
public:
  ExampleLayer(): Layer("Example") { }

  void OnUpdate() override {
    if (Haru::Input::IsKeyPressed(HARU_KEY_TAB)) HARU_TRACE("Tab key is pressed (poll)!");
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
    PushOverlay(new Haru::ImGuiLayer());
  }

  ~SandBox() { }
};

Haru::Application *Haru::CreateApplication() { return new SandBox(); }