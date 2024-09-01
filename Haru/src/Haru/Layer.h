/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : Layer.h
 @brief   :
===========================================================================
*/

#ifndef LAYER_H
#define LAYER_H

#include "Haru/Core.h"
#include "Haru/Events/Event.h"

namespace Haru {
/***********************************************************************

  Layer

***********************************************************************/

class HARU_API Layer {
public:
  Layer(const std::string &name = "Layer");
  virtual ~Layer();
  // Similar to Init(), when a layer is in the layer stack.
  virtual void OnAttach(){};
  // Similar to Shutdown(), when a layer is removed from the layer stack.
  virtual void OnDetach(){};
  // Render
  virtual void OnUpdate(){}; 
  // Process event
  virtual void OnEvent(Event &event) {}
  inline const std::string &GetName() const { return m_DebugName; }

protected:
  bool isEnabled; // false mean not to render
  std::string m_DebugName;
};

} // namespace Haru

#endif // !LAYER_H
