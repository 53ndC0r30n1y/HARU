/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : ImGuiLayer.cpp
 @brief   : ImGui layer
===========================================================================
*/
#include "Harupch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Haru/Application.h"

namespace Haru {
/***********************************************************************

  ImGuiLayer

***********************************************************************/

/*
============================================================================
  ImGuiLayer::ImGuiLayer
============================================================================
*/
ImGuiLayer::ImGuiLayer():
  Layer("ImGuiLayer") { }
/*
============================================================================
  ImGuiLayer::~ImGuiLayer
============================================================================
*/
ImGuiLayer::~ImGuiLayer() { }
/*
============================================================================
  ImGuiLayer::OnAttach
============================================================================
*/
void ImGuiLayer::OnAttach() {
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   // Enable Docking
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
  // io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
  // io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // custom style from ImThemes
  ImGuiStyle &style = ImGui::GetStyle();

  ImFont *font = io.Fonts->AddFontFromFileTTF(
    "../../../../../res/font/Alibaba-PuHuiTi-Medium.ttf", // pwd:Xen/bin/
    22,
    nullptr,
    io.Fonts->GetGlyphRangesChineseFull()); // load chinese

  IM_ASSERT(font != nullptr); // 必须判断一下字体有没有加载成功

  style.Alpha                     = 1.0f;
  style.DisabledAlpha             = 0.6000000238418579f;
  style.WindowPadding             = ImVec2(6.0f, 3.0f);
  style.WindowRounding            = 3.0f;
  style.WindowBorderSize          = 1.0f;
  style.WindowMinSize             = ImVec2(32.0f, 32.0f);
  style.WindowTitleAlign          = ImVec2(0.5f, 0.5f);
  style.WindowMenuButtonPosition  = ImGuiDir_Left;
  style.ChildRounding             = 3.0f;
  style.ChildBorderSize           = 1.0f;
  style.PopupRounding             = 3.0f;
  style.PopupBorderSize           = 1.0f;
  style.FramePadding              = ImVec2(5.0f, 1.0f);
  style.FrameRounding             = 3.0f;
  style.FrameBorderSize           = 1.0f;
  style.ItemSpacing               = ImVec2(8.0f, 4.0f);
  style.ItemInnerSpacing          = ImVec2(4.0f, 4.0f);
  style.CellPadding               = ImVec2(4.0f, 2.0f);
  style.IndentSpacing             = 21.0f;
  style.ColumnsMinSpacing         = 6.0f;
  style.ScrollbarSize             = 10.39999961853027f;
  style.ScrollbarRounding         = 16.0f;
  style.GrabMinSize               = 20.0f;
  style.GrabRounding              = 2.0f;
  style.TabRounding               = 4.0f;
  style.TabBorderSize             = 0.0f;
  style.TabMinWidthForCloseButton = 0.0f;
  style.ColorButtonPosition       = ImGuiDir_Right;
  style.ButtonTextAlign           = ImVec2(0.5f, 0.5f);
  style.SelectableTextAlign       = ImVec2(0.0f, 0.0f);
  style.TabBarOverlineSize        = 0.0f;

  // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    style.WindowRounding              = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }

  style.Colors[ImGuiCol_Text] = ImVec4(0.8588235378265381f, 0.929411768913269f, 0.886274516582489f, 1.0f);
  style.Colors[ImGuiCol_TextDisabled] =
    ImVec4(0.8588235378265381f, 0.929411768913269f, 0.886274516582489f, 0.2784313857555389f);
  style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
  style.Colors[ImGuiCol_ChildBg]  = ImVec4(0.1294117718935013f, 0.1176470592617989f, 0.1137254908680916f, 1.0f);
  style.Colors[ImGuiCol_PopupBg] =
    ImVec4(0.1294117718935013f, 0.1176470592617989f, 0.1137254908680916f, 0.9019607901573181f);
  style.Colors[ImGuiCol_Border] =
    ImVec4(0.9450980424880981f, 0.8941176533699036f, 0.8039215803146362f, 0.1607843190431595f);
  style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
  style.Colors[ImGuiCol_FrameBg]      = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_FrameBgHovered] =
    ImVec4(0.2000000029802322f, 0.1764705926179886f, 0.1607843190431595f, 0.4705882370471954f);
  style.Colors[ImGuiCol_FrameBgActive] =
    ImVec4(0.1490196138620377f, 0.05490196123719215f, 0.007843137718737125f, 0.47843137383461f);
  style.Colors[ImGuiCol_TitleBg]          = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.5098039507865906f);
  style.Colors[ImGuiCol_TitleBgActive]    = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.8156862854957581f);
  style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.5098039507865906f);
  style.Colors[ImGuiCol_MenuBarBg]        = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_ScrollbarBg]      = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_ScrollbarGrab] =
    ImVec4(0.5529412031173706f, 0.2980392277240753f, 0.1411764770746231f, 0.7803921699523926f);
  style.Colors[ImGuiCol_ScrollbarGrabHovered] =
    ImVec4(0.5529412031173706f, 0.2980392277240753f, 0.1411764770746231f, 1.0f);
  style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_CheckMark]        = ImVec4(0.1882352977991104f, 1.0f, 0.1647058874368668f, 0.7098039388656616f);
  style.Colors[ImGuiCol_SliderGrab]       = ImVec4(0.5529412031173706f, 0.2980392277240753f, 0.1411764770746231f, 1.0f);
  style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_Button]           = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_ButtonHovered] =
    ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 0.4980392158031464f);
  style.Colors[ImGuiCol_ButtonActive]     = ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 1.0f);
  style.Colors[ImGuiCol_Header]           = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.5098039507865906f);
  style.Colors[ImGuiCol_HeaderHovered]    = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.7647058963775635f);
  style.Colors[ImGuiCol_HeaderActive]     = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_Separator]        = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.501960813999176f);
  style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.7803921699523926f);
  style.Colors[ImGuiCol_SeparatorActive]  = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_ResizeGrip]       = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_ResizeGripHovered] =
    ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 0.7803921699523926f);
  style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 1.0f);
  style.Colors[ImGuiCol_Tab]              = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_TabHovered]       = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
  style.Colors[ImGuiCol_TabActive]        = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
  style.Colors[ImGuiCol_TabUnfocused]     = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
  style.Colors[ImGuiCol_TabUnfocusedActive] =
    ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
  style.Colors[ImGuiCol_PlotLines] =
    ImVec4(0.9411764740943909f, 0.8901960849761963f, 0.800000011920929f, 0.6549019813537598f);
  style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_PlotHistogram]    = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 0.7529411911964417f);
  style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
  style.Colors[ImGuiCol_TableBorderStrong] =
    ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
  style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
  style.Colors[ImGuiCol_TableRowBg]       = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
  style.Colors[ImGuiCol_TableRowBgAlt]    = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
  style.Colors[ImGuiCol_TextSelectedBg] =
    ImVec4(0.4549019634723663f, 0.196078434586525f, 0.2980392277240753f, 0.4300000071525574f);
  style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
  style.Colors[ImGuiCol_NavHighlight]          = ImVec4(0.9803921580314636f, 0.5882353186607361f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
  style.Colors[ImGuiCol_NavWindowingDimBg] =
    ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
  style.Colors[ImGuiCol_ModalWindowDimBg] =
    ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);

  Application &app    = Application::Get();
  GLFWwindow  *window = static_cast<GLFWwindow *>(app.GetWindow().GetNativeWindow());

  // Setup Platform/Renderer bindings
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 410");
}
/*
============================================================================
  ImGuiLayer::OnDetach
============================================================================
*/
void ImGuiLayer::OnDetach() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
/*
============================================================================
  ImGuiLayer::Begin
============================================================================
*/
void ImGuiLayer::Begin() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}
/*
============================================================================
  ImGuiLayer::End
============================================================================
*/
void ImGuiLayer::End() { // ready to render window
  ImGuiIO     &io  = ImGui::GetIO();
  Application &app = Application::Get();
  io.DisplaySize   = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

  // Rendering
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    GLFWwindow *backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
  }
} /*
 ============================================================================
   ImGuiLayer::OnGuiRender
 ============================================================================
 */
void ImGuiLayer::OnImGuiRender() {
  static bool show = true;
  ImGui::ShowDemoWindow(&show);
}

} // namespace Haru