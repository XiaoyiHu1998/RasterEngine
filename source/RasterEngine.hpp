#ifndef RASTER_ENGINE_HPP
#define RASTER_ENGINE_HPP

#include "masterInclude.hpp"
#include "World.hpp"
#include "Renderer.hpp"
#include "MeshImporter_OBJ.hpp"

class RasterEngine{
private:
    // World world;
    // Renderer renderer;
    // MeshImporter_OBJ importer_obj;
    
    void update();
    void render();
public:
    RasterEngine();
    void reset();
    void tick();
};

#endif //RASTER_ENGINE_HPP