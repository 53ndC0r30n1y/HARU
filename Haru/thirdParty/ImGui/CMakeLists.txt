cmake_minimum_required(VERSION 3.15)
project(ImGui)

add_library(${PROJECT_NAME} STATIC 
  	ImGui/imconfig.h
	ImGui/imgui.h
	ImGui/imgui.cpp
	ImGui/imgui_draw.cpp
	ImGui/imgui_internal.h
	ImGui/imgui_tables.cpp
	ImGui/imgui_widgets.cpp
	ImGui/imstb_rectpack.h
	ImGui/imstb_textedit.h
	ImGui/imstb_truetype.h
	ImGui/imgui_demo.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "thirdParty")
target_include_directories(${PROJECT_NAME} PUBLIC ImGui/)
