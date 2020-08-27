#include "RendererManager.hpp"

RendererManager::RendererManager(GLFWwindow* window, std::shared_ptr<World> worldPointer, std::shared_ptr<ImportManager> importManagerPointer):
    scene{SceneRenderer(worldPointer)},
    ui{UIRenderer(window, importManagerPointer)}
    {}

void RendererManager::renderProgramWindow(){
    ui.drawWindows(scene.renderScene());
    ui.drawImGui();
}