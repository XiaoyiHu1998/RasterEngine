#ifndef SCENE_RENDERER_HPP
#define SCENE_RENDERER_HPP

#include "World.hpp"

class SceneRenderer{
private:
    std::shared_ptr<World> worldPointer;
    unsigned int frameBuffer;
    unsigned int colorTexture;
    unsigned int renderBuffer;
    vector2i renderResolution;
public:
    SceneRenderer(std::shared_ptr<World> worldPointer);
    void init();
    void setRenderResolution(ImVec2 viewportSize);
    unsigned int renderScene();
};

#endif //SCENE_RENDERER_HPP