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

  // Adds a Layer * to the stack of layers
  void PushLayer(Layer *layer);

  // Adds a Layer * to the stack of overlays
  void PushOverlay(Layer *overlay);

  // Removes a specific Layer * from the stack of layers
  void PopLayer(Layer *layer);

  // Removes a specific Layer * from the stack of overlays
  void PopOverlay(Layer *overlay);

  // Returns an iterator pointing to the first element in m_Layers
  std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }

  // Returns an iterator pointing one past the last element in m_Layers
  std::vector<Layer *>::iterator end() { return m_Layers.end(); }

protected:
  // Vector storing pointers to Layer objects
  std::vector<Layer *> m_Layers;

  // Iterator used for tracking insertion position in m_Layers
  std::vector<Layer *>::iterator m_LayerInsert;
};
} // namespace Haru

#endif // !LAYERSTACK_H
