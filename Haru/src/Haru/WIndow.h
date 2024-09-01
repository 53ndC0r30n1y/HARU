/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : Window.h
 @brief   :
===========================================================================
*/

#ifndef WINDOW_H
#define WINDOW_H

#include "Haru/Core.h"
#include "Haru/Events/Event.h"
#include "Harupch.h"

namespace Haru {
/***********************************************************************

  Window

***********************************************************************/
struct WindowProps {
  std::string Title;
  unsigned int Width;
  unsigned int Height;
  WindowProps(const std::string &title = "Haru Engine",
              unsigned int width = 1280, unsigned int height = 720)
      : Title(title), Width(width), Height(height) {}
};

class HARU_API Window {
public:
  // call back function
  using EventCallbackFn = std::function<void(Event &)>;
  virtual ~Window() {}         // virtual
  virtual void OnUpdate() = 0; // pure virtual
  virtual unsigned int GetWidth() const = 0;
  virtual unsigned int GetHeight() const = 0;

  // Window attributes
  virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
  virtual void SetVSync(bool enabled) = 0;
  virtual bool IsVSync() const = 0;

  // static calss share by eyery child class
  static Window *Create(const WindowProps &props = WindowProps());
};
} // namespace Haru

#endif