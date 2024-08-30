#include "Haru.h"

class SandBox : public Haru::Application {
 public:
  SandBox() {}

  ~SandBox() {}
};

Haru::Application* Haru::CreateApplication() { return new SandBox(); }