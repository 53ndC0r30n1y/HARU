/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : ImGuiBuild.h
 @brief   : This header file includes necessary implementations for integrating
            ImGui with OpenGL and GLFW. It sets up the appropriate loader for
            OpenGL and includes the implementation files for ImGui's backend
            for OpenGL and GLFW.

            The `IMGUI_IMPL_OPENGL_LOADER_GLAD` macro defines that the OpenGL
            loader used is GLAD. This ensures that the necessary OpenGL function
            pointers are loaded at runtime using GLAD.

            Including `imgui_impl_opengl3.cpp` and `imgui_impl_glfw.cpp` provides
            the implementation of ImGui's rendering backend for OpenGL 3 and the
            GLFW windowing system. These files are typically used to integrate
            ImGui's user interface capabilities with OpenGL and GLFW in a
            cross-platform manner.

 @note    : Ensure that the necessary libraries for ImGui, OpenGL, GLFW, and GLAD
            are properly linked in your project for successful compilation and
            linking.

===========================================================================
*/
#include "Harupch.h"

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui_impl_opengl3.cpp"
#include "imgui_impl_glfw.cpp"