#ifndef UI_RENDERER_HPP
#define UI_RENDERER_HPP

#include "masterInclude.hpp"
#include "ImportManager.hpp"

class UIRenderer{
private:
    GLFWwindow* window;
    bool sceneViewport;
    bool systemInfo;
    bool importFile;

    std::shared_ptr<ImportManager> importManagerPointer;
    ImVec2 viewportSize;

    void draw3DViewport(unsigned int colorTextures);
public:
    UIRenderer(GLFWwindow* window, std::shared_ptr<ImportManager> importManagerPointer);
    void drawWindows(unsigned int colorTexture);
    void drawImGui();
    ImVec2 getViewportSize();
};

#endif //UI_RENDERER_HPP