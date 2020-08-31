#ifndef SCENE_RENDERER_HPP
#define SCENE_RENDERER_HPP

#include "Scene.hpp"

class SceneRenderer{
private:
    std::shared_ptr<Scene> scenePointer;
    unsigned int frameBuffer;
    unsigned int colorTexture;
    unsigned int renderBuffer;
    
    int screenWidth;
    int screenHeight;
    ImVec4 clear_color;
    float colorDelta;
    
    void bindFrameBuffer();
    void unbindFrameBuffer();
public:
    SceneRenderer(std::shared_ptr<Scene> scenePointer);
    void createFrameBuffer();
    void setRenderResolution(ImVec2 viewportSize);
    unsigned int renderScene();
};

#endif //SCENE_RENDERER_HPP