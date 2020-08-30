#include "RendererManager.hpp"

RendererManager::RendererManager(GLFWwindow* window, std::shared_ptr<World> worldPointer, std::shared_ptr<ImportManager> importManagerPointer):
    scene{SceneRenderer(worldPointer)},
    ui{UIRenderer(window, importManagerPointer)}
    {}

void RendererManager::init(){
    scene.createFrameBuffer();
}

void RendererManager::renderScene(){
    colorTexture = scene.renderScene();
}

void RendererManager::renderProgramWindow(){
    ui.drawUI(colorTexture);
    ui.drawToScreen();
    scene.setRenderResolution(ui.getViewportSize());
}