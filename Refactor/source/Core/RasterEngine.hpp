#ifndef RASTER_ENGINE_HPP
#define RASTER_ENGINE_HPP

#include "namespace.hpp"
#include "Viewport.hpp"
#include "UI.hpp"

class RasterEngine{
private:
    Scene scene;

    void initViewport(GLFWwindow* window);
    void initUI();
public:
    RasterEngine(GLFWwindow* window);
    void draw();
};

#endif //RASTER_ENGINE_HPP