/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : OpenGLContext.cpp
 @brief   :
===========================================================================
*/
#include "Harupch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <GLAD/glad.h>
#include <GL/GL.h>

namespace Haru {
/*
============================================================================
  OpenGLContext::OpenGLContext
============================================================================
*/
OpenGLContext::OpenGLContext(GLFWwindow *windowHandle):
  m_WindowHandle(windowHandle) {
  HARU_CORE_ASSERT(windowHandle, "Window handle is null!");
}
/*
============================================================================
  OpenGLContext::Init
============================================================================
*/
void OpenGLContext::Init() {
  glfwMakeContextCurrent(m_WindowHandle);
  int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  HARU_CORE_ASSERT(status, "Failed to initialize Glad!");
}
/*
============================================================================
  OpenGLContext::SwapBuffers
============================================================================
*/
void OpenGLContext::SwapBuffers() { glfwSwapBuffers(m_WindowHandle); }
} // namespace Haru