#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include "Scene.hpp"

namespace Engine{
    GLFWwindow* window;
    Scene scene;

    namespace Viewport{
        //scene render result
        unsigned int renderTexture; 
        unsigned int frameBuffer;
        unsigned int renderBuffer;

        ImVec4 clearColor;
        bool sizeChanged;
        float colorDelta;
        int width;
        int height;
    }

    namespace UI{
        ImVec2 viewportSize;
        bool importFile;
        bool sceneViewport;
        bool outliner;
        bool properties;
        bool performanceMetrics;
        bool demoWindow;
    }
}

#endif //NAMESPACE_HPP