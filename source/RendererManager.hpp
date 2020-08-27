#ifndef RENDERER_MANAGER_HPP
#define RENDERER_MANAGER_HPP

#include "SceneRenderer.hpp"
#include "UIRenderer.hpp"

class RendererManager{
private:
    SceneRenderer scene;
    UIRenderer ui;
public:
    RendererManager(GLFWwindow* window, std::shared_ptr<World> worldPointer, std::shared_ptr<ImportManager> importManagerPointer);
    void renderProgramWindow();
};

#endif //RENDERER_MANAGER_HPP