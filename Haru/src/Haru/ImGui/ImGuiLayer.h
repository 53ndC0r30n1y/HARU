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

namespace Haru{
/***********************************************************************

  ImGuiLayer

***********************************************************************/
class HARU_API ImGuiLayer : public Layer{
public:
  ImGuiLayer();
  ~ImGuiLayer();

  void OnAttach();
  void OnDetach();
  void OnUpdate();
  void OnEvent(Event& event);

private:
  float m_Time = 0.0f;
};

}

#endif // !IMGUILAYER_H
