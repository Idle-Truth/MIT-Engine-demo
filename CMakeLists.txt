cmake_minimum_required(VERSION 4.0)
project(MIT_Engine_demo)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ENGINE_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/main.cpp)
add_executable(MIT_Engine_demo ${ENGINE_SOURCES}
        platforms/IGraphicsAPI.h
        platforms/VulkanAPI.cpp
        platforms/MetalAPI.cpp
        platforms/MetalAPI.cpp
        platforms/DirectXAPI.cpp)

# Always include vendor headers
target_include_directories(MIT_Engine_demo PRIVATE
        ${CMAKE_SOURCE_DIR}/vendor/glfw-3.4/include
        ${CMAKE_SOURCE_DIR}/vendor/glm
        ${CMAKE_SOURCE_DIR}/vendor/OpenXR-SDK/include
        ${CMAKE_SOURCE_DIR}/vendor/
        ${CMAKE_SOURCE_DIR}/platforms/
)

if (WIN32)
    # Force console subsystem for MinGW with multiple flags
    target_link_options(MIT_Engine_demo PRIVATE
            -mconsole
            -Wl,--subsystem,console
    )

    # Vulkan setup
    target_include_directories(MIT_Engine_demo PRIVATE $ENV{VULKAN_SDK}/Include)

    # Set full paths to libraries
    set(GLFW_LIB "${CMAKE_SOURCE_DIR}/vendor/glfw-3.4/src/libglfw3.a")
    set(VULKAN_LIB "$ENV{VULKAN_SDK}/Lib/vulkan-1.lib")
    set(OPENXR_LIB "${CMAKE_SOURCE_DIR}/vendor/OpenXR-SDK/build/src/loader/libopenxr_loader.a")

    target_link_libraries(MIT_Engine_demo
            PRIVATE
            "${GLFW_LIB}"
            "${VULKAN_LIB}"
            "${OPENXR_LIB}"
    )

elseif (UNIX)
    find_package(Vulkan REQUIRED)
    target_include_directories(MIT_Engine_demo PRIVATE ${Vulkan_INCLUDE_DIRS})

    target_link_libraries(MIT_Engine_demo
            PRIVATE
            glfw
            ${Vulkan_LIBRARIES}
            OpenXR::openxr_loader
    )
endif()

target_compile_options(MIT_Engine_demo PRIVATE
        -Wall -Wextra -Wpedantic
)

add_custom_command(TARGET MIT_Engine_demo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:MIT_Engine_demo>/shaders
)
