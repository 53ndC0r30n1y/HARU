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

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS
    src/*.h
)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES
    src/*.cpp
)

# generate library
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_HEADERS} ${${PROJECT_NAME}_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Game")

# 检查是否启用了 USE_SOLUTION_FOLDERS 标志
if (USE_SOLUTION_FOLDERS)
    # 定义宏 SOURCE_GROUP_BY_FOLDER
    # 该宏用于根据文件所在的目录在 IDE 中进行分组
    MACRO(SOURCE_GROUP_BY_FOLDER target)
        # 设置路径分隔符，用于分组
        SET(SOURCE_GROUP_DELIMITER "/")       
        # 初始化变量
        SET(last_dir "")  # 上一个目录
        SET(files "")     # 当前目录下的文件列表
        # 遍历目标的源文件和头文件
        FOREACH(file ${${target}_HEADERS} ${${target}_SOURCES})         
            # 获取文件相对于项目源目录的相对路径
            file(RELATIVE_PATH relative_file "${PROJECT_SOURCE_DIR}" ${file})    
            # 获取文件所在的目录
            GET_FILENAME_COMPONENT(dir "${relative_file}" PATH)     
            # 如果当前目录与上一个目录不同
            IF (NOT "${dir}" STREQUAL "${last_dir}")     
                # 如果有文件已经累积，创建一个新的 SOURCE_GROUP
                IF (files)
                    SOURCE_GROUP("${last_dir}" FILES ${files})
                ENDIF (files)     
                # 清空当前目录下的文件列表
                SET(files "")
            ENDIF (NOT "${dir}" STREQUAL "${last_dir}")  
            # 将当前文件添加到文件列表中
            SET(files ${files} ${file})  
            # 更新上一个目录
            SET(last_dir "${dir}")
        ENDFOREACH(file)
        # 如果还有剩余文件，创建最后一个 SOURCE_GROUP
        IF (files)
            SOURCE_GROUP("${last_dir}" FILES ${files})
        ENDIF (files)
    ENDMACRO(SOURCE_GROUP_BY_FOLDER)
    # 设置要进行分组的目标模型
    set(XEN "Xen")
    # 调用宏，对指定目标进行分组
    SOURCE_GROUP_BY_FOLDER(${XEN})
    # 查找所有根目录(HARU/Haru)下的 .cxx 和 .h 文件
    file(GLOB root_All "${PROJECT_SOURCE_DIR}" *.cpp *.h)
    # 将所有根目录下的文件添加到一个顶级的 SOURCE_GROUP
    SOURCE_GROUP("" FILES ${root_All})
endif()


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

# Copy DLL file to executable file directory
#add_custom_command(TARGET Xen POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    ${CMAKE_CURRENT_BINARY_DIR}/../Haru/bin/Haru.dll
#    ${CMAKE_CURRENT_BINARY_DIR}/bin
#)