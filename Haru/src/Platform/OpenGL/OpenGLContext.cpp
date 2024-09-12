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

  HARU_CORE_INFO("OpenGL Info:");

  const GLubyte *vendor   = glGetString(GL_VENDOR);
  const GLubyte *renderer = glGetString(GL_RENDERER);
  const GLubyte *version  = glGetString(GL_VERSION);

  std::string vendorStr(reinterpret_cast<const char *>(vendor));
  std::string rendererStr(reinterpret_cast<const char *>(renderer));
  std::string versionStr(reinterpret_cast<const char *>(version));

  HARU_CORE_INFO("  Vendor: {}", vendorStr);
  HARU_CORE_INFO("  Renderer: {}", rendererStr);
  HARU_CORE_INFO("  Version: {}", versionStr);
}
/*
============================================================================
  OpenGLContext::SwapBuffers
============================================================================
*/
void OpenGLContext::SwapBuffers() { glfwSwapBuffers(m_WindowHandle); }
} // namespace Haru