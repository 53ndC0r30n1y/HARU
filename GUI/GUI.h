#ifndef GUI_H
#define GUI_H

#include <GL/glew.h>	// OpenGL的函数调用，并初始化 ，
#include <GLFW/glfw3.h>	// 窗口绘制工具

#include <string>
#include <vector>

#include "imgui.h"

class GUI {
public:

    GUI(int width, int height, const std::string& title);
    ~GUI();

    void SetupImGuiStyle();

    // Listen for events on the RenderWindow.
    void pollEvents();

    // Update all UI elements to reflect state changes.
    void update();

    // Update the window to reflect state changes.
    void Render();
    bool ShouldClose() const;

private:
    GLFWwindow* window;
};


#endif