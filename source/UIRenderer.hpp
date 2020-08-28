#ifndef UI_RENDERER_HPP
#define UI_RENDERER_HPP

#include "masterInclude.hpp"
#include "ImportManager.hpp"

class UIRenderer{
private:
    GLFWwindow* window;
    bool importFile;
    bool sceneViewport;
    bool outliner;
    bool properties;
    bool performanceMetrics;

    std::shared_ptr<ImportManager> importManagerPointer;
    ImVec2 viewportSize;

    void drawMainMenuBar();
    void drawOpenWindows(unsigned int colorTexture);
    void draw3DViewport(unsigned int colorTexture);
public:
    UIRenderer(GLFWwindow* window, std::shared_ptr<ImportManager> importManagerPointer);
    void drawUI(unsigned int colorTexture);
    void drawToScreen();
    ImVec2 getViewportSize();
};

#endif //UI_RENDERER_HPP