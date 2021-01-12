#ifndef RASTER_ENGINE_HPP
#define RASTER_ENGINE_HPP

#include "masterInclude.hpp"
#include "Scene.hpp"
#include "RendererManager.hpp"
#include "ImportManager.hpp"

class RasterEngine{
private:
    Scene scene;
    ImportManager importManager;
    RendererManager rendererManager;
    
public:
    RasterEngine(GLFWwindow* window);
    void draw();
};

#endif //RASTER_ENGINE_HPP