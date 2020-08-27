#include "RasterEngine.hpp"

RasterEngine::RasterEngine(GLFWwindow* window):
    world{World()},
    importManager{ImportManager(std::make_shared<World>(world))},
    rendererManager{RendererManager(window, std::make_shared<World>(world), std::make_shared<ImportManager>(importManager))}
    {
        rendererManager.init();
    }

void RasterEngine::draw(){
    rendererManager.renderProgramWindow();
}

void RasterEngine::drawSceneToTexture(){
    rendererManager.renderScene();
}