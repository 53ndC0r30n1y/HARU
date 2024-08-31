/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : Application.cpp
 @brief   :
===========================================================================
*/

#include "Application.h"

#include "Harupch.h"
#include "Log.h"

// #include <GL/glew.h>
#include <GLFW/glfw3.h>

/***********************************************************************

  Application

***********************************************************************/

namespace Haru {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
/*
============================================================================
  Application::Application
============================================================================
*/
Application::Application() {
  m_Window = std::unique_ptr<Window>(Window::Create());  // ´´½¨´°¿Ú
  // Window init call back function
  m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}
/*
============================================================================
  Application::~Application
============================================================================
*/
Application::~Application() {}
/*
============================================================================
  Application::PushLayer
============================================================================
*/
void Application::PushLayer(Layer *layer){ m_LayerStack.PushLayer(layer);}
/*
============================================================================
  Application::PushOverlay
============================================================================
*/
void Application::PushOverlay(Layer *layer) { m_LayerStack.PushOverlay(layer); }
/*
============================================================================
  Application::OnEvent
============================================================================
*/
void Application::OnEvent(Event& e) {
  EventDispatcher dispatcher(e);
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

  for(auto it = m_LayerStack.end();it != m_LayerStack.begin();){
    (*--it)->OnEvent(e);
    if (e.Handled)
      break;
  }
}
/*
============================================================================
  Application::Run
============================================================================
*/
void Application::Run() {
  while (m_Running) {
    // Clear Screen
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    for (Layer *layer : m_LayerStack)
      layer->OnUpdate();

    m_Window->OnUpdate();  // update glfw
  }
}
/*
============================================================================
  Application::OnWindowClose
============================================================================
*/
bool Application::OnWindowClose(WindowCloseEvent& e) {
  m_Running = false;
  return true;
}
}  // namespace Haru