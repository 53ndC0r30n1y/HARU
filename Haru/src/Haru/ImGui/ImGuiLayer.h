/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-09-01 15:19
 @file    : ImGuiLayer.h
 @brief   : Imgui layer
===========================================================================
*/

#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Haru/Layer.h"

#include "Haru/Events/ApplicationEvent.h"
#include "Haru/Events/KeyEvent.h"
#include "Haru/Events/MouseEvent.h"
namespace Haru {
/***********************************************************************

  ImGuiLayer

***********************************************************************/
class HARU_API ImGuiLayer : public Layer {
public:
  ImGuiLayer();
  ~ImGuiLayer();

  void OnAttach();
  void OnDetach(); 
  void OnUpdate();
  void OnEvent(Event &event);

private:
  bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);
  bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);
  bool OnMouseMovedEvent(MouseMovedEvent &e);
  bool OnMouseScrolledEvent(MouseScrolledEvent &e);
  bool OnKeyPressedEvent(KeyPressedEvent &e);
  bool OnKeyReleasedEvent(KeyReleasedEvent &e);
  bool OnKeyTypedEvent(KeyTypedEvent &e);
  bool OnWindowResizeEvent(WindowResizeEvent &e);

  float m_Time = 0.0f;
};

} // namespace Haru

#endif // !IMGUILAYER_H
