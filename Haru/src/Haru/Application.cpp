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

// #include <GL/glew.h>
#include <glad/glad.h> //need macro GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

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

  m_ImGuiLayer = new ImGuiLayer();
  PushLayer(m_ImGuiLayer);

  glGenVertexArrays(1, &m_VertexArray);
  glBindVertexArray(m_VertexArray);

  glGenBuffers(1, &m_VertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

  float vertices[3 * 3] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

  glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),nullptr);

  glGenBuffers(1,&m_IndexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IndexBuffer);

  unsigned int indices[3] = {0,1,2};
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
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
    glClearColor(0.1f, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(m_VertexArray);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

    // Update normal layer
    for (Layer *layer : m_LayerStack)
      layer->OnUpdate();

    // begin to reder ImGui
    m_ImGuiLayer->Begin();
    for (Layer *layer : m_LayerStack)
      layer->OnImGuiRender();
    m_ImGuiLayer->End(); // render done

    // update window (GLFW)
    m_Window->OnUpdate();
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