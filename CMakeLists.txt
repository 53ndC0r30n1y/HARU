cmake_minimum_required(VERSION 3.15)

project (HARU)

option(USE_SOLUTION_FOLDERS "使用资源管理器文件夹" OFF)

# Solution folders
if(USE_SOLUTION_FOLDERS)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "HARU")
endif()

# static lib
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
# dynamic lib
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
# executable file
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
include(Dependencies)

set(CMAKE_GENERATOR_PLATFORM x64)

# Dependencies
#add_subdirectory(Haru/thirdParty/Box2D)
#add_subdirectory(Haru/thirdParty/GLFW)
add_subdirectory(Haru/thirdParty/GLAD)
add_subdirectory(Haru/thirdParty/ImGui)
#add_subdirectory(Haru/thirdParty/yaml-cpp)

# Core
add_subdirectory(Haru)

# Tools
# add_subdirectory()

# Misc
add_subdirectory(Xen)