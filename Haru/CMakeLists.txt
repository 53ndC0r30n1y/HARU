cmake_minimum_required(VERSION 3.15)
project(Haru)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# static lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
# dynamic lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
# executable file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# option(BOX2D_BUILD_UNIT_TESTS "Build the Box2D unit tests" OFF)
# option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)
# option(BOX2D_BUILD_DOCS "Build the Box2D documentation" OFF)
# option(BOX2D_USER_SETTINGS "Override Box2D settings with b2UserSettings.h" OFF)
# option(BUILD_SHARED_LIBS "Build Box2D as a shared library" ON)

file(GLOB_RECURSE HARU_HEADERS
    src/*.h
    # thirdParty/stb_image/*.h
    # thirdParty/glm/glm/*.hpp
    # thirdParty/ImGuizmo/ImGuizmo.h
)

file(GLOB_RECURSE HARU_SOURCES
    src/*.cpp
    # thirdParty/stb_image/*.cpp
    # thirdParty/glm/glm/*.inl
    # thirdParty/ImGuizmo/ImGuizmo.cpp
)

# generate library
add_library(${PROJECT_NAME} STATIC  ${HARU_HEADERS} ${HARU_SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE src/Harupch.h)

# Add compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    HARU_PLATFORM_WINDOWS
    HARU_BUILD_DLL 
    _CRT_SECURE_NO_WARNINGS
    GLFW_INCLUDE_NONE
)

# include path
target_include_directories(${PROJECT_NAME} PRIVATE
    src
    ${IncludeDir_spdlog}
    ${IncludeDir_GLFW}
    ${IncludeDir_GLAD}
    # ${IncludeDir_glm}    
    # ${IncludeDir_ImGui}    
    # ${IncludeDir_Box2D}
    # ${IncludeDir_filewatch}
    # ${IncludeDir_stb_image}
    # ${IncludeDir_entt}
    # ${IncludeDir_mono}
    # ${IncludeDir_yaml_cpp}
    # ${IncludeDir_ImGuizmo}
    # ${IncludeDir_VulkanSDK}
)

# message("IncludeDir_VulkanSDK: ${IncludeDir_VulkanSDK}")

# link path
target_link_libraries(${PROJECT_NAME} PRIVATE
#    box2d
     ${Library_GLFW}
     GLAD
#    imgui
#    yaml-cpp
     opengl32.lib
#    # ${Library_mono}
)

# if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
#     target_link_libraries(${PROJECT_NAME} PRIVATE
#         ${Library_WinSock}
#         ${Library_WinMM}
#         ${Library_WinVersion}
#         ${Library_BCrypt}
#     )
# endif()

# compile option
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:/EHsc>
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE HARU_DEBUG)
    target_compile_options(${PROJECT_NAME} PRIVATE /Od /Zi)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${Library_ShaderC_Debug}
        ${Library_SPIRV_Cross_Debug}
        ${Library_SPIRV_Cross_GLSL_Debug}
    )
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE HARU_RELEASE)
    target_compile_options(${PROJECT_NAME} PRIVATE /O2)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${Library_ShaderC_Release}
        ${Library_SPIRV_Cross_Release}
        ${Library_SPIRV_Cross_GLSL_Release}
    )
elseif (CMAKE_BUILD_TYPE STREQUAL "Dist")
    target_compile_definitions(${PROJECT_NAME} PRIVATE HARU_DIST)
    target_compile_options(${PROJECT_NAME} PRIVATE /O2)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${Library_ShaderC_Release}
        ${Library_SPIRV_Cross_Release}
        ${Library_SPIRV_Cross_GLSL_Release}
    )
endif()