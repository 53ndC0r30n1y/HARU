#include "GUI.h"

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "implot.h"
#include "implot_internal.h"

#include <stdexcept>


void GUI::SetupImGuiStyle() {
	// 设置颜色主题
	ImGui::StyleColorsDark();

	// dk2 style from ImThemes
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.6000000238418579f;
	style.WindowPadding = ImVec2(6.0f, 3.0f);
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5.0f, 1.0f);
	style.FrameRounding = 3.0f;
	style.FrameBorderSize = 1.0f;
	style.ItemSpacing = ImVec2(8.0f, 4.0f);
	style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
	style.CellPadding = ImVec2(4.0f, 2.0f);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 10.39999961853027f;
	style.ScrollbarRounding = 16.0f;
	style.GrabMinSize = 20.0f;
	style.GrabRounding = 2.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 1.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(0.8588235378265381f, 0.929411768913269f, 0.886274516582489f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.8588235378265381f, 0.929411768913269f, 0.886274516582489f, 0.2784313857555389f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.1294117718935013f, 0.1176470592617989f, 0.1137254908680916f, 1.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.1294117718935013f, 0.1176470592617989f, 0.1137254908680916f, 0.9019607901573181f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.9450980424880981f, 0.8941176533699036f, 0.8039215803146362f, 0.1607843190431595f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2000000029802322f, 0.1764705926179886f, 0.1607843190431595f, 0.4705882370471954f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.1490196138620377f, 0.05490196123719215f, 0.007843137718737125f, 0.47843137383461f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.5098039507865906f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.8156862854957581f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.5098039507865906f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.5529412031173706f, 0.2980392277240753f, 0.1411764770746231f, 0.7803921699523926f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.5529412031173706f, 0.2980392277240753f, 0.1411764770746231f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.1882352977991104f, 1.0f, 0.1647058874368668f, 0.7098039388656616f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.5529412031173706f, 0.2980392277240753f, 0.1411764770746231f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 0.4980392158031464f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.5098039507865906f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.7647058963775635f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.501960813999176f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 0.7803921699523926f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.9764705896377563f, 0.4862745106220245f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 0.7803921699523926f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.5921568870544434f, 0.239215686917305f, 0.2431372553110123f, 1.0f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1450980454683304f, 0.1333333402872086f, 0.1176470592617989f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.9411764740943909f, 0.8901960849761963f, 0.800000011920929f, 0.6549019813537598f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 0.7529411911964417f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.9803921580314636f, 0.4901960790157318f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.4549019634723663f, 0.196078434586525f, 0.2980392277240753f, 0.4300000071525574f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.9803921580314636f, 0.5882353186607361f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

GUI::GUI(int width, int height, const std::string& title) {

	glfwInit();										// 用 GLFW 初始化窗口
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// OpenGL主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	// OpenGL次版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //使用核心模式

	//获取窗口指针
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(window);//给予控制权
	glfwSwapInterval(0);            //关闭垂直同步

	// 初始化 ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext(NULL);
	ImPlot::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io; //获取 io，设置 ImGUI 内容
	//设置字体
	io.Fonts->AddFontFromFileTTF("../res/font/Alibaba-PuHuiTi-Medium.ttf", 22, NULL, io.Fonts->GetGlyphRangesChineseFull());

	//允许窗口停靠
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//关闭视窗样式，允许自定义样式
	io.ConfigFlags |= ImGuiViewportFlags_NoDecoration;
	//允许多个独立视窗存在
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	//允许窗口背景
	io.ConfigFlags |= ImGuiCol_DockingEmptyBg;

	SetupImGuiStyle();//设置 ImGUi 窗口配色

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

}

GUI::~GUI() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	ImPlot::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}



void GUI::pollEvents() {

}

void GUI::update() {
	static bool pOpen = true;
	static bool show_app_log = false;

	if (!ImGui::Begin("Stats Viewer", &pOpen, ImGuiWindowFlags_MenuBar))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
	}

	if (ImGui::BeginMenuBar()) {
		if (ImGui::BeginMenu("Examples"))
		{
			ImGui::MenuItem("Log", NULL, &show_app_log);
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}


	if (ImGui::CollapsingHeader("Decay Curve"))
	{
		ImGui::Text("Number of weapons to compare:");
		ImGui::SameLine();

		static int counter = 1;
		static int counter_last = 0;

		float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
		if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { counter--; if (counter < 1) counter = 1; }
		ImGui::SameLine(0.0f, spacing);
		if (ImGui::ArrowButton("##right", ImGuiDir_Right)) { counter++; if (counter > 10) counter = 10; }
		ImGui::SameLine();
		ImGui::Text(" %d", counter);
	}

	//ImPlot::ShowDemoWindow();
	//ImGui::ShowDemoWindow();

	ImGui::End();
}

void GUI::Render() {
	//清除渲染数据
	glClear(GL_COLOR_BUFFER_BIT);

	//为每一帧的 ImGUI 初始化
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	// 创建窗口停靠
	ImGui::DockSpaceOverViewport();

	GUI::update();

	//获取绘制数据
	ImGui::Render();
	//渲染绘制数据
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO(); (void)io; //获取 io，设置 ImGUI 内容
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		//当窗口拖出窗口范围，创建子窗口
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}

	//绘制窗口内容
	glfwSwapBuffers(window);
	//绘制事件
	glfwPollEvents();
}

bool GUI::ShouldClose() const {
	return glfwWindowShouldClose(window);
}

