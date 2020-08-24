#ifndef RASTER_ENGINE_HPP
#define RASTER_ENGINE_HPP

#include "masterInclude.hpp"
#include "World.hpp"
#include "Renderer.hpp"
#include "ImportManager.hpp"

class RasterEngine{
private:
    World world;
    // Renderer renderer;
    // MeshImporter_OBJ importer_obj;
    ImportManager importManager;
    bool importFile;
    bool systemInfo;
    bool viewport;
    
    void update();
    void render();
public:
    RasterEngine();
    void reset();
    void tick();
    void renderUI();
};

#endif //RASTER_ENGINE_HPP