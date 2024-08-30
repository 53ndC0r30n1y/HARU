cmake_minimum_required(VERSION 3.15)
project(HARA)

set(IncludeDir)
set(IncludeDir_spdlog "${CMAKE_SOURCE_DIR}/Haru/thirdParty/spdlog/include")
# set(IncludeDir_stb_image "${CMAKE_SOURCE_DIR}/Haru/thirdParty/stb_image")
# set(IncludeDir_yaml_cpp "${CMAKE_SOURCE_DIR}/Haru/thirdParty/yaml-cpp/include")
# set(IncludeDir_Box2D "${CMAKE_SOURCE_DIR}/Haru/thirdParty/Box2D/include")
# set(IncludeDir_filewatch "${CMAKE_SOURCE_DIR}/Haru/thirdParty/filewatch")
set(IncludeDir_GLFW "${CMAKE_SOURCE_DIR}/Haru/thirdParty/GLFW/include")
# set(IncludeDir_GLEW "E:/Libraries/GLEW")
set(IncludeDir_GLAD "${CMAKE_SOURCE_DIR}/Haru/thirdParty/GLAD/include/")
set(IncludeDir_ImGui "${CMAKE_SOURCE_DIR}/Haru/thirdParty/ImGui/ImGui")
# set(IncludeDir_ImGuizmo "${CMAKE_SOURCE_DIR}/Haru/thirdParty/ImGuizmo")
set(IncludeDir_GLM "${CMAKE_SOURCE_DIR}/Haru/thirdParty/GLM")
# set(IncludeDir_entt "${CMAKE_SOURCE_DIR}/Haru/thirdParty/entt/include")
# set(IncludeDir_mono "${CMAKE_SOURCE_DIR}/Haru/thirdParty/mono/include")
# set(IncludeDir_shaderc "${CMAKE_SOURCE_DIR}/Haru/thirdParty/shaderc/include")
# set(IncludeDir_SPIRV_Cross "${CMAKE_SOURCE_DIR}/Haru/thirdParty/SPIRV-Cross")
# set(IncludeDir_VulkanSDK "${VULKAN_SDK}/Include")


set(LibraryDir)

# set(LibraryDir_VulkanSDK "${VULKAN_SDK}/Lib")
# set(LibraryDir_mono "${CMAKE_SOURCE_DIR}/Haru/thirdParty/mono/lib/%{cfg.buildcfg}") # TODO: fix this

set(Library)
set(Library_GLFW "${CMAKE_SOURCE_DIR}/Haru/thirdParty/GLFW/lib-vc2022/glfw3.lib")
# set(Library_GLEW "E:/Libraries/GLEW/glew32.lib")
# set(Library_mono "${LibraryDir_mono}/libmono-static-sgen.lib")

# set(Library_Vulkan "${LibraryDir_VulkanSDK}/vulkan-1.lib")
# set(Library_VulkanUtils "${LibraryDir_VulkanSDK}/VkLayer_utils.lib")

# set(Library_ShaderC_Debug "${LibraryDir_VulkanSDK}/shaderc_sharedd.lib")
# set(Library_SPIRV_Cross_Debug "${LibraryDir_VulkanSDK}/spirv-cross-cored.lib")
# set(Library_SPIRV_Cross_GLSL_Debug "${LibraryDir_VulkanSDK}/spirv-cross-glsld.lib")
# set(Library_SPIRV_Tools_Debug "${LibraryDir_VulkanSDK}/SPIRV-Toolsd.lib")

# set(Library_ShaderC_Release "${LibraryDir_VulkanSDK}/shaderc_shared.lib")
# set(Library_SPIRV_Cross_Release "${LibraryDir_VulkanSDK}/spirv-cross-core.lib")
# set(Library_SPIRV_Cross_GLSL_Release "${LibraryDir_VulkanSDK}/spirv-cross-glsl.lib")

# Windows
# set(Library_WinSock "Ws2_32.lib")
# set(Library_WinMM "Winmm.lib")
# set(Library_WinVersion "Version.lib")
# set(Library_BCrypt "Bcrypt.lib")
