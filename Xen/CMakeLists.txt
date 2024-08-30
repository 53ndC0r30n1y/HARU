cmake_minimum_required(VERSION 3.15)
project(Xen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# static lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
# dynamic lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
# executable file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)

# generate .exe
add_executable(${PROJECT_NAME} ${SOURCES})

# include path
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/Haru/src
    ${IncludeDir_spdlog}
    
    # ${CMAKE_SOURCE_DIR}/Haru/thirdParty
    # ${CMAKE_SOURCE_DIR}/Haru/thirdParty/imgui
    # ${CMAKE_SOURCE_DIR}/Haru/thirdParty/Glad
    # ${IncludeDir_glm}
    # ${IncludeDir_entt}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Haru
)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        HARU_PLATFORM_WINDOWS 
        HARU_DEBUG
    )
endif()

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

# 拷贝 DLL 文件到可执行文件目录
#add_custom_command(TARGET Xen POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    ${CMAKE_CURRENT_BINARY_DIR}/../Haru/bin/Haru.dll
#    ${CMAKE_CURRENT_BINARY_DIR}/bin
#)