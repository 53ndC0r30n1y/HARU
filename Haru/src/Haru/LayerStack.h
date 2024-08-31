/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : LayerStack.h
 @brief   :
===========================================================================
*/

#ifndef LAYERSTACK_H
#define LAYERSATCK_H

#include "Haru/Core.h"
#include "Layer.h"

#include "Harupch.h"

namespace Haru {
/***********************************************************************

  LayerStack

***********************************************************************/

class HARU_API LayerStack {
public:
  LayerStack();
  ~LayerStack();

  void PushLayer(Layer *layer);
  void PushOverlay(Layer *overlay);
  void PopLayer(Layer *layer);
  void PopOverlay(Layer *overlay);

  std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
  std::vector<Layer *>::iterator end() { return m_Layers.end(); }

protected:
  std::vector<Layer *> m_Layers;
  std::vector<Layer *>::iterator m_LayerInsert;

};
} // namespace Haru

#endif // !LAYERSTACK_H
