#ifndef APPLICATION_H
#define APPLICATION_H

#include "Haru/Core.h"

#include "Haru/Window.h"
#include "Haru/LayerStack.h"
#include "Haru/Events/Event.h"
#include "Haru/Events/ApplicationEvent.h"

namespace Haru {
class HARU_API Application {
public:
  Application();
  virtual ~Application();

  void Run();

  void OnEvent(Event &e);
  void PushLayer(Layer *layer);
  void PushOverlay(Layer *layer);

private:
  bool OnWindowClose(WindowCloseEvent &e);

  std::unique_ptr<Window> m_Window;
  bool m_Running = true;
  LayerStack m_LayerStack;
};
// To be defined in CLIENT
Application *CreateApplication();
} // namespace Haru

#endif // !APPLICATION_H
