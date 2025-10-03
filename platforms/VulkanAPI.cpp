#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "IGraphicsAPI.h"


void VulkanAPI::initVulkan() {
    // Vulkan initialization code
}

void VulkanAPI::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Store in member variable instead of local
    window = glfwCreateWindow(width, height, "MIT-Engine-demo", nullptr, nullptr);

}


void VulkanAPI::run() {
    initWindow();
    initVulkan();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        DrawFrame();
    }

    //cleanup();

}

void VulkanAPI::CreateBuffer() {
    // Vulkan buffer creation implementation
}

void VulkanAPI::CreateTexture() {
    // Vulkan texture creation implementation
}

void VulkanAPI::DrawFrame() {
    // Vulkan rendering implementation
}


