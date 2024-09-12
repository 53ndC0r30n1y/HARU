/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : OpenGLContext.h
 @brief   :
===========================================================================
*/
#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include "Haru/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Haru{
  class OpenGLContext : public GraphicsContext{
  public:
    OpenGLContext(GLFWwindow *windowHandle);

    virtual void Init() override;
    virtual void SwapBuffers() override;

  private:
    GLFWwindow *m_WindowHandle;
  };
}

#endif // !OPENGLCONTEXT_H
