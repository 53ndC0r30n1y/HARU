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

virtual void OnAttach() override;
virtual void OnDetach() override;
virtual void OnImGuiRender() override;

void Begin();
void End();

private:
  float m_Time = 0.0f;
};

} // namespace Haru

#endif // !IMGUILAYER_H
