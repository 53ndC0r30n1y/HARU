cmake_minimum_required(VERSION 3.15)

project (HARU)

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

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# 包含子项目。
add_subdirectory ("Haru")
add_subdirectory ("Xen")

