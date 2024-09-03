/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : Application.cpp
 @brief   :
===========================================================================
*/

#include "Haru/Application.h"

#include "Harupch.h"
#include "Haru/Log.h"

// #include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h> //need macro GLFW_INCLUDE_NONE

#include "Haru/Input.h"
/***********************************************************************

  Application

***********************************************************************/

namespace Haru {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
Application *Application::s_Instance = nullptr;
/*
============================================================================
  Application::Application
============================================================================
*/
Application::Application() {
  HARU_CORE_ASSERT(!s_Instance, "Application already exists!");
  s_Instance = this;

  m_Window = std::unique_ptr<Window>(Window::Create()); // ´´½¨´°¿Ú
  // Window init call back function
  m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}
/*
============================================================================
  Application::~Application
============================================================================
*/
Application::~Application() { }
/*
============================================================================
  Application::PushLayer
============================================================================
*/
void Application::PushLayer(Layer *layer) {
  m_LayerStack.PushLayer(layer);
  layer->OnAttach();
}
/*
============================================================================
  Application::PushOverlay
============================================================================
*/
void Application::PushOverlay(Layer *layer) {
  m_LayerStack.PushOverlay(layer);
  layer->OnAttach();
}
/*
============================================================================
  Application::OnEvent
============================================================================
*/
void Application::OnEvent(Event &e) { // EventHandler
  EventDispatcher dispatcher(e);      // EventListener,Observer of Observe Pattern
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

  for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
    (*--it)->OnEvent(e);
    if (e.Handled) break;
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

    m_Window->OnUpdate(); // update glfw
  }
}
/*
============================================================================
  Application::OnWindowClose
============================================================================
*/
bool Application::OnWindowClose(WindowCloseEvent &e) {
  m_Running = false;
  return true;
}
} // namespace Haru