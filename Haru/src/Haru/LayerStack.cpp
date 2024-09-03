/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : LayerStack.cpp
 @brief   :
===========================================================================
*/

#include "LayerStack.h"
#include "Harupch.h"

namespace Haru {
/***********************************************************************

  Layer Stack

***********************************************************************/

/*
============================================================================
  LayerStack::LayerStack
============================================================================
*/
LayerStack::LayerStack() { }
/*
============================================================================
  LayerStack::~LayerStack
============================================================================
*/
LayerStack::~LayerStack() {
  for (Layer *layer : m_Layers)
    delete layer;
}
/*
============================================================================
  LayerStack::PushLayer
============================================================================
*/
void LayerStack::PushLayer(Layer *layer) {
  m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
  m_LayerInsertIndex++;
}
/*
============================================================================
  LayerStack::PushOverlay
============================================================================
*/
void LayerStack::PushOverlay(Layer *overlay) { m_Layers.emplace_back(overlay); }
/*
============================================================================
  LayerStack::PopLayer
============================================================================
*/
void LayerStack::PopLayer(Layer *layer) {
  auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
  if (it != m_Layers.end()) {
    m_Layers.erase(it);
    m_LayerInsertIndex--;
  }
}
/*
============================================================================
  LayerStack::PopOverlay
============================================================================
*/
void LayerStack::PopOverlay(Layer *overlay) {
  auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
  if (it != m_Layers.end()) m_Layers.erase(it);
}

} // namespace Haru