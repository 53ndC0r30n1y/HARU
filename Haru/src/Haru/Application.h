/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : Application.h
 @brief   :
===========================================================================
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Haru/Core.h"

#include "Haru/Window.h"
#include "Haru/LayerStack.h"
#include "Haru/Events/Event.h"
#include "Haru/Events/ApplicationEvent.h"
#include "Haru/ImGui/ImGuiLayer.h"
/***********************************************************************

  Application

***********************************************************************/

namespace Haru {
/*
============================================================================
  Application
============================================================================
*/
class HARU_API Application {
public:
  Application();
  virtual ~Application();

  void Run();

  void OnEvent(Event &e);
  void PushLayer(Layer *layer);
  void PushOverlay(Layer *layer);

  inline Window             &GetWindow() { return *m_Window; }
  inline static Application &Get() { return *s_Instance; }

private:
  bool OnWindowClose(WindowCloseEvent &e);

  std::unique_ptr<Window> m_Window;
  ImGuiLayer             *m_ImGuiLayer;
  bool                    m_Running = true;
  LayerStack              m_LayerStack;

  static Application *s_Instance;
};
// To be defined in CLIENT
Application *CreateApplication();
} // namespace Haru

#endif // !APPLICATION_H
