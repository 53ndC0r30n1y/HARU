/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : WindowsInput.cpp
 @brief   :
===========================================================================
*/

#include "Harupch.h"
#include "WindowsInput.h"

#include "Haru/Application.h"
#include <GLFW/glfw3.h>

namespace Haru {
/***********************************************************************

  Windows Input

***********************************************************************/

Input *Input::s_Instance = new WindowsInput();
/*
============================================================================
  WindowsInput::IsKeyPressedImpl
============================================================================
*/
bool WindowsInput::IsKeyPressedImpl(int keycode) {
  auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
  auto state  = glfwGetKey(window, keycode);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}
/*
============================================================================
  WindowsInput::IsMouseButtonPressedImpl
============================================================================
*/
bool WindowsInput::IsMouseButtonPressedImpl(int button) {
  auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
  auto state  = glfwGetMouseButton(window, button);
  return state == GLFW_PRESS;
}
/*
============================================================================
  WindowsInput::GetMousePositionImpl
============================================================================
*/
std::pair<float, float> WindowsInput::GetMousePositionImpl() {
  auto   window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);

  return {(float)xpos, (float)ypos};
}
/*
============================================================================
  WindowsInput::GetMouseXImpl
============================================================================
*/
float WindowsInput::GetMouseXImpl() {
  auto [x, y] = GetMousePositionImpl();
  return x;
}
/*
============================================================================
  WindowsInput::GetMouseYImpl
============================================================================
*/
float WindowsInput::GetMouseYImpl() {
  auto [x, y] = GetMousePositionImpl();
  return y;
}

} // namespace Haru