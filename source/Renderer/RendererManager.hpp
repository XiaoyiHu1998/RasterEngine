#ifndef RENDERER_MANAGER_HPP
#define RENDERER_MANAGER_HPP

#include "SceneRenderer.hpp"
#include "UIRenderer.hpp"

class RendererManager{
private:
    SceneRenderer scene;
    UIRenderer ui;

    unsigned int colorTexture;
public:
    RendererManager(GLFWwindow* window, std::shared_ptr<Scene> scenePointer, std::shared_ptr<ImportManager> importManagerPointer);
    void init();
    void renderScene();
    void renderProgramWindow();
};

#endif //RENDERER_MANAGER_HPP