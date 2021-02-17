#include "RendererManager.hpp"

RendererManager::RendererManager(GLFWwindow* window, std::shared_ptr<Scene> scenePointer, std::shared_ptr<ImportManager> importManagerPointer):
    scene{SceneRenderer(scenePointer)},
    ui{UIRenderer(window, importManagerPointer)}
    {}

void RendererManager::init(){
    scene.createFrameBuffer();
}

void RendererManager::renderProgramWindow(){
    colorTexture = scene.renderScene();

    ui.drawUI(colorTexture);
    ui.drawToScreen();

    ImVec2 viewportSize = ui.getViewportSize();
    scene.setRenderResolution(viewportSize);
}