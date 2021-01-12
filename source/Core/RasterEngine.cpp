#include "RasterEngine.hpp"

RasterEngine::RasterEngine(GLFWwindow* window):
    scene{Scene()},
    importManager{ImportManager(std::make_shared<Scene>(scene))},
    rendererManager{RendererManager(window, std::make_shared<Scene>(scene), std::make_shared<ImportManager>(importManager))}
    {
        rendererManager.init();
    }

void RasterEngine::draw(){
    rendererManager.renderProgramWindow();
}