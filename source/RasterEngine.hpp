#ifndef RASTER_ENGINE_HPP
#define RASTER_ENGINE_HPP

#include "masterInclude.hpp"
#include "World.hpp"
#include "RendererManager.hpp"
#include "ImportManager.hpp"

class RasterEngine{
private:
    World world;
    ImportManager importManager;
    RendererManager rendererManager;
    
public:
    RasterEngine(GLFWwindow* window);
    void draw();
};

#endif //RASTER_ENGINE_HPP