//
// Created by Trey on 10/2/2025.
//

#ifndef MIT_ENGINE_DEMO_IGRAPHICSAPI_H
#define MIT_ENGINE_DEMO_IGRAPHICSAPI_H
#include <GLFW/glfw3.h>


class IGraphicsAPI {
    public:
        virtual ~IGraphicsAPI() = default;
        virtual void CreateBuffer() = 0;
        virtual void CreateTexture() = 0;
        virtual void DrawFrame() = 0;
    };

class VulkanAPI : public IGraphicsAPI {
public:
    // Interface overrides (these MUST have override)
    void CreateBuffer() override;
    void CreateTexture() override;
    void DrawFrame() override;

    // Vulkan-specific functions (NO override keyword)
    void initWindow();
    void initVulkan();
    void run();
    GLFWwindow* getWindow() const { return window; }

private:
    GLFWwindow* window;
    const int width = 800;
    const int height = 600;
};



class MetalAPI : public IGraphicsAPI {

};

class DirectXAPI : public IGraphicsAPI {

};



#endif //MIT_ENGINE_DEMO_IGRAPHICSAPI_H