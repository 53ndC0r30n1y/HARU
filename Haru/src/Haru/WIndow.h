#ifndef WINDOW_H
#define WINDOW_H

#include "Haru/Core.h"
#include "Haru/Events/Event.h"
#include "Harupch.h"

namespace Haru {
struct WindowProps {
  std::string Title;
  unsigned int Width;
  unsigned int Height;
  WindowProps(const std::string& title = "Haru Engine",
              unsigned int width = 1280, unsigned int height = 720)
      : Title(title), Width(width), Height(height) {}
};

class HARU_API Window {
 public:
  using EventCallbackFn = std::function<void(Event&)>;  // call back function
  virtual ~Window() {}
  virtual void OnUpdate() = 0;
  virtual unsigned int GetWidth() const = 0;
  virtual unsigned int GetHeight() const = 0;
  // Window attributes
  virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
  virtual void SetVSync(bool enabled) = 0;
  virtual bool IsVSync() const = 0;

  static Window* Create(const WindowProps& props = WindowProps());
};
}  // namespace Haru

#endif